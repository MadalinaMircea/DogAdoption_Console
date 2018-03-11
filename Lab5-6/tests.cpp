#include "Controller.h"
#include "assert.h"
#include "tests.h"
#include<iostream>
#include <string>
#include "Exceptions.h"
using namespace std;

void testDog()
{
	string breed = "Beagle", name = "Sean", photo = "www.google.com";
	Dog dog = Dog{ breed, name, 3, photo };
	photo = "www.facebook.com";
	Dog doggo = Dog{ breed, name, 5, photo };

	assert(dog == doggo);

	assert(dog.getCurrentInstances() == 2);
	assert(dog.getAllInstances() > 0);
	
	assert(dog.getBreed() == "Beagle");
	assert(dog.getName() ==  "Sean");
	assert(dog.getPhoto() == "www.google.com");
	assert(dog.getAge() == 3);

	dog.setAge(6);
	assert(dog.getAge() == 6);

	dog.setPhoto("www.facebook.com");
	assert(dog.getPhoto() == "www.facebook.com");

	breed = "Westie"; name = "Bolt"; photo = "www.facebook.com";
	dog = Dog{ breed, name, 1, photo };

	assert(dog.getBreed() == "Westie");
	assert(dog.getName() == "Bolt");
	assert(dog.getPhoto() == "www.facebook.com");
	assert(dog.getAge() == 1);

	dog.setAge(10);
	assert(dog.getAge() == 10);

	dog.setPhoto("www.google.com");
	assert(dog.getPhoto() == "www.google.com");

	dog.setName("Bolty");
	assert(dog.getName() == "Bolty");

	dog.setBreed("Pomeranian");
	assert(dog.getBreed() == "Pomeranian");

	dog.showPicture();
}

void testRepository()
{
	Repository* repo = new Repository;
	
	assert(repo->dogs.getSize() == 0);
	
	repo->init();
	assert(repo->dogs.getSize() == 10);

	assert(repo->dogs.elems[0].getBreed() == "Beagle");

	assert(repo->dogs.elems[2].getName() == "Bez");

	assert(repo->dogs.elems[6].getPhoto() == "https://s-media-cache-ak0.pinimg.com/736x/20/69/00/206900a83822e1a875f0617a33cecf07.jpg");

	assert(repo->dogs.elems[9].getAge() == 1);

	string breed = "Bulldog", name = "Dancer", photo = "website";
	Dog dog = Dog{ breed, name, 3, photo };

	repo->add(dog);

	assert(repo->dogs.getSize() == 11);

	assert(repo->dogs.elems[10].getAge() == 3);
	
	assert(repo->dogs.elems[10].getBreed() == "Bulldog");
	
	breed = "Bichon Frise"; name = "Vixen", photo = "www";
	dog = Dog{ breed, name, 5, photo };
	repo->update(4, dog);
	
	assert(repo->dogs.elems[4].getName() == "Vixen");

	assert(repo->dogs.elems[4].getAge() == 5);

	repo->remove(6);

	assert(repo->dogs.elems[6].getAge() == 2);

	assert(repo->dogs.getSize() == 10);

	assert(repo->dogs.elems[8].getName() == "Minnie");
	
	delete repo;
}

void testDynamicVector()
{
	DynamicVectorSTL<Dog> elements;

	string breed = "Beagle", name = "Sean", photo = "www.google.com";
	Dog dog = Dog{ breed, name, 3, photo };

	elements = elements + dog;
	elements = dog + elements;

	assert(elements.getSize() == 2);
	
	DynamicVectorSTL<Dog> newElements = DynamicVectorSTL<Dog>(elements);
	
	assert(newElements.getSize() == 2);
	
}

void testController()
{
	FileRepository* repo = new FileRepository;
	Controller* ctrl = new Controller{ repo };

	assert(ctrl->repo->dogs.getSize() == 0);

	ctrl->repo->init();

	assert(ctrl->repo->dogs.getSize() == 10);

	assert(repo->dogs.elems[1].getBreed() == "Westie");

	assert(repo->dogs.elems[5].getName() == "Boy");

	assert(repo->dogs.elems[7].getPhoto() == "http://i.huffpost.com/gen/3753474/images/o-PUG-facebook.jpg");

	assert(repo->dogs.elems[3].getAge() == 3);

	string breed, name, photo;

	try
	{
		breed = "Pomeranian", name = "Minnie", photo = "www";
		ctrl->add(breed, name, 4, photo);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}

	try
	{
		breed = "Boo"; name = "Baby"; photo = "www";
		ctrl->add(breed, name, 1, photo);
		assert(true);
	}
	catch (DuplicateDogException& e)
	{
		assert(false);
	}

	assert(ctrl->repo->dogs.getSize() == 11);

	breed = "Bulldog"; name = "Wrinkle"; photo = "www";
	string newBreed = "Bulldog", newName = "Wrinkles";
	try
	{
		ctrl->update(breed, name, 3, photo, newBreed, newName);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}

	breed = "Beagle"; name = "Bailey"; photo = "www"; newBreed = "Beagle"; newName = "Bailey";
	try
	{
		ctrl->update(breed, name, 6, photo, newBreed, newName);
		assert(true);
	}
	catch (...)
	{
		assert(false);
	}

	assert(ctrl->repo->dogs.elems[0].getAge() == 6);

	breed = "Snautzer"; name = "Chris";
	try
	{
		ctrl->remove(breed, name);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}

	breed = "Pomeranian"; name = "Minnie";
	try
	{
		ctrl->remove(breed, name);
		assert(true);
	}
	catch (...)
	{
		assert(false);
	}

	assert(ctrl->repo->dogs.getSize() == 10);

	breed = "Beagle"; name = "Bailey"; photo = ""; newBreed = ""; newName = "";
	try
	{
		ctrl->update(breed, name, 0, photo, newBreed, newName);
		assert(true);
	}
	catch (...)
	{
		assert(false);
	}

	delete ctrl;
}

void runAllTests()
{
	testDog();
	testRepository();
	testController();
	testDynamicVector();
}
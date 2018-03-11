#include "Repository.h"

void Repository::add(Dog& dog)
{
	this->dogs = this->dogs + dog;
}

void Repository::init()
{
	string breed = "Beagle", name = "Bailey", photo = "http://superpesik.ru/wp-content/uploads/2013/09/bigl-xarer7.JPG";
	Dog dog = Dog(breed, name, 5, photo);

	this->add(dog);

	breed = "Westie"; name = "Bolt"; photo = "http://cdn.akc.org/westie_puppy.jpg";
	dog = Dog(breed, name, 2, photo);

	this->add(dog);

	breed = "Labrador"; name = "Bez"; photo = "http://cdn1-www.dogtime.com/assets/uploads/gallery/labrador-retriever-dog-breed-pictures/labrador-retriever-dog-pictures-1.jpg";
	dog = Dog(breed, name, 1, photo);

	this->add(dog);

	breed = "Golden Retriever";  name = "Honey"; photo = "http://static.animalzoo.ro/uploads/2015/08/golden2.jpg";
	dog = Dog(breed, name, 3, photo);

	this->add(dog);

	breed = "Bichon Havanese";  name = "Cody"; photo = "https://i.ytimg.com/vi/ItMCpfBmKgY/hqdefault.jpg";
	dog = Dog(breed, name, 7, photo);

	this->add(dog);

	breed = "Bichon Frise";  name = "Boy"; photo = "http://www.dogbreedslist.info/uploads/allimg/dog-pictures/Bichon-Frise-3.jpg";
	dog = Dog(breed, name, 1, photo);

	this->add(dog);

	breed = "Doberman";  name = "Tooth"; photo = "https://s-media-cache-ak0.pinimg.com/736x/20/69/00/206900a83822e1a875f0617a33cecf07.jpg";
	dog = Dog(breed, name, 8, photo);

	this->add(dog);

	breed = "Pug";  name = "Princess"; photo = "http://i.huffpost.com/gen/3753474/images/o-PUG-facebook.jpg";
	dog = Dog(breed, name, 2, photo);

	this->add(dog);

	breed = "Pitbull";  name = "Charlie"; photo = "http://americanbullydaily.com/wp-content/uploads/2016/01/Pitbull-Dog-Smiling.jpg";
	dog = Dog(breed, name, 3, photo);

	this->add(dog);

	breed = "Pomeranian";  name = "Minnie"; photo = "http://www.yeartohelp.com/wp-content/uploads/2012/10/boo.jpg";
	dog = Dog(breed, name, 1, photo);

	this->add(dog);
	
}

void Repository::remove(int index)
{
	this->dogs.remove(index);
}

void Repository::update(int index, Dog& d)
{
	this->dogs.update(index, d);
}
#include <iostream>

using namespace std;

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
void insert(int);
void display();
void delete_list();

class Shape  //a pure virual class to specify the shape 
{
public:
	Shape(){}
	virtual float area(){ return 0.0; }
	virtual void displayInfo(){};
};


class Rectangle :public Shape //rectangle which inherits virual functions of shape
{
private:
	float base;
	float height;
public:
	Rectangle(float b, float h)  //consturctor for Rectangle class
	{
		base = b;
		height = h;
	}
	virtual float area(){ return base*height; } //gives us the area a virtual implementation of a virtual function 
	virtual void displayInfo() //displays the information for the rectange a virtual implementation of a virtual function
	{
		cout << "This is a rectangle." << endl;
		cout << "Base: " << base << endl;
		cout << "Height: " << height << endl;
		cout << "Area: " << this->area() << endl;
	}
	float getBase(){ return base; }//needed for square area function for work
	float getHeight(){ return height; } //needed for square area fucntion to work

};

class Circle :public Shape
{
private:
	float radius;
public:
	Circle(float r){ radius = r; }  //circle constructor 
	float area(){ return radius*radius*PI; } // computation of the circle area
	void displayInfo() //displays information foa circle
	{
		cout << "This is a circle." << endl;
		cout << "Radius: " << radius << endl;
		cout << "Area: " << this->area() << endl;
	}
};

class Square :public Rectangle
{
public:
	Square(float b) :Rectangle(b, b){} //use the Rectangle constructor to build a square
	float area(){ return this->getBase()*this->getBase(); } //area uses the gets for bade and height
	void displayInfo() //displays the information for a square
	{
		cout << "This is a square." << endl;
		cout << "Base: " << this->getBase() << endl;
		cout << "Height: " << this->getHeight() << endl;
		cout << "Area: " << this->area() << endl;
	}
};

class ShapeCollection  //the linked list for shape collection
{
private:
	Shape *shape;              //The shape payload for the node
	ShapeCollection *next;     //The next pointer
public:
	ShapeCollection(Shape * newShape) //ShapeCollection constructor
	{
		shape = newShape;
		next = NULL;
	}
	~ShapeCollection(){ delete shape; } //ShapeCollection destructor

	Shape * getShape(){ return shape; } //Returns the shape payload pointer
	ShapeCollection * getNext(){ return next; } //returns the next pointer
	void setNext(ShapeCollection* newNode){ next = newNode; } //sets the next pointer
};

ShapeCollection *head; //The global head of the linked list 
/*************************************************
FOR THE LOVE OF GOD, when you are coding in real life do not use
global variables for importnant buffers this is the number one way to
exploit live programs!!!!!
*************************************************/

int main(void)
{
	int choice, shapeChoice;
	/******************************
	The do while for the menu of our program
	*****************************/
	do
	{
		cout << "Shape Program Menu:" << endl;
		cout << "(1) Add a shape" << endl;
		cout << "(2) print all" << endl;
		cout << "(3) quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:   //this case is for inserting a shape
		{
			/*Insert shape menu*/
			cout << "What kind of shape would you like to create?" << endl;
			cout << "(1) Circle" << endl;
			cout << "(2) Rectangle" << endl;
			cout << "(3) Square" << endl;
			cin >> shapeChoice;
			if (choice >= 1 || choice <= 3)
				insert(shapeChoice);
			else
				cout << "Invalid selection." << endl << endl;
			break;
		}
		case 2:
		{
			display(); //display the contents of the shape collection in head
			break;
		}
		case 3:
		{
			break;
		}
		default:
			cout << "Invalid Choice!" << endl;
			break;
		}
	} while (choice != 3);
	delete_list(); //clean up the list before exiting the program
	return 0;
}
/**********************************************
Insert in the crux of using the linked list, I highly suggest
you stack trace (go through the function line by line) to figure out
what it does.
**********************************************/
void insert(int choice) //inserts a new shape into the ShapeCollectoion ll
{
	float base;
	float height;
	float radius;
	Shape *newShape;
	ShapeCollection *iterator;
	if (choice==1)
	{
		cout << "radius? ";
		cin >> radius;
		newShape = new Circle(radius);
	}
	else if (choice==2)
	{
		cout << "Base? ";
		cin >> base;
		cout << "Height? ";
		cin >> height;
		newShape = new Rectangle(base, height);
	}
	else 
	{
		cout << "Side? ";
		cin >> base;
		newShape = new Square(base);
	}
	
	if (head == NULL)
		head = new ShapeCollection(newShape);
	else
	{
		iterator = head;
		while (iterator->getNext() != NULL) iterator = iterator->getNext();
		iterator->setNext((ShapeCollection *)new ShapeCollection(newShape));
	}
}

void display()   //displays the contents of the ShapeCollection Linked list
{
	ShapeCollection *iterator;       //the iterator for our linked list
	cout << endl; //new line for clarity
	if (head != NULL) //if head of the list is null (list empty) we do nothing
	{
		iterator = head;     //set the iterator to the fist entry
		do
		{
			iterator->getShape()->displayInfo(); //display info for first entry
			iterator = iterator->getNext();   //increment the list iterator
			cout << endl;  //new line for clarity
		} while (iterator != NULL);
	}
	else
		cout << "The List is empty!" << endl << endl; //tell the luser the list is empty
}
/*Removes every entry in the list*/
void delete_list()
{
	ShapeCollection *dummy;  //use a dummy to hold the old list head
	dummy = head;  //set dummy to the first entry in the list
	while (dummy != NULL)  //iterate over the list deleting the head node each time
	{
		head = head->getNext(); //move the head node to the next node in the list
		delete dummy; //delete the previous head node
		dummy = head; //reset dummy to the head so we can delete that too
	}

}

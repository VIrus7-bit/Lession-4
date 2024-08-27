#include <iostream>﻿
#include <string>

class Figure
{
protected:
	std::string nameFigure_;
	bool haveFourSides_ = false;
	int sideLengthA_ = 0;
	int sideLengthB_ = 0;
	int sideLengthC_ = 0;
	int sideLengthD_ = 0;
	int angleA_ = 0;
	int angleB_ = 0;
	int angleC_ = 0;
	int angleD_ = 0;

public:
	std::string getNameOfFigure() { return nameFigure_; }
	int getHaveFourSides() { return haveFourSides_; }

	int getSideLengthA() { return sideLengthA_; }
	int getSideLengthB() { return sideLengthB_; }
	int getSideLengthC() { return sideLengthC_; }
	int getSideLengthD() { return sideLengthD_; }

	int getAngleA() { return angleA_; }
	int getAngleB() { return angleB_; }
	int getAngleC() { return angleC_; }
	int getAngleD() { return angleD_; }
};

class Triangle : public Figure
{
public:
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
	{
		nameFigure_ = "Треугольник";
		sideLengthA_ = sideLengthA;
		sideLengthB_ = sideLengthB;
		sideLengthC_ = sideLengthC;
		angleA_ = angleA;
		angleB_ = angleB;
		angleC_ = angleC;
	}
};
class rightTriangle : public Triangle{

	public:rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB): Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, 90)
	{Triangle::nameFigure_ = "Прямоугольный треугольник";};
};
class isoscelesTriangle : public Triangle{

	public:isoscelesTriangle(int sideLengthA, int sideLengthB, int angleA, int angleB): Triangle(sideLengthA, sideLengthB, sideLengthA, angleA, angleB, angleA)
	{Triangle::nameFigure_ = "Равнобедренный треугольник";};
};
class equilateralTriangle : public Triangle{

	public:equilateralTriangle(int sideLengthA): Triangle(sideLengthA, sideLengthA, sideLengthA, 60, 60, 60)
	{Triangle::nameFigure_ = "Равносторонний треугольник";};
};
class Quadrilateral : public Figure{
	public:Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		nameFigure_ = "Четырехугольник";
		haveFourSides_ = true;

		sideLengthA_ = sideLengthA;
		sideLengthB_ = sideLengthB;
		sideLengthC_ = sideLengthC;
		sideLengthD_ = sideLengthD;

		angleA_ = angleA;
		angleB_ = angleB;
		angleC_ = angleC;
		angleD_ = angleD;
	}
};
class Rectangle : public Quadrilateral{
	public: Rectangle(int sideLengthA, int sideLengthB): Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, 90, 90, 90, 90)
	{Quadrilateral::nameFigure_ = "Прямоугольник";}
};
class Square : public Quadrilateral{
	public:Square(int sideLengthA): Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, 90, 90, 90, 90)
	{Quadrilateral::nameFigure_ = "Квадрат";}
};
class Parallelogram : public Quadrilateral{
	public:Parallelogram(int sideLengthA, int sideLengthB, int angleA, int angleB): Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, angleA, angleB, angleA, angleB)
	{Quadrilateral::nameFigure_ = "Параллелограмм";}
};
class Rhomb : public Quadrilateral{
	public:Rhomb(int sideLengthA, int angleA, int angleB): Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, angleA, angleB, angleA, angleB)
	{Quadrilateral::nameFigure_ = "Ромб";}
};

void printFigure(Figure& figure){

	std::cout << std::endl ; std::cout << figure.getNameOfFigure() << ":" << std::endl;
	std::cout << "Стороны:"; std::cout << " a = " << figure.getSideLengthA() << ", b = " << figure.getSideLengthB() << ", с = " << figure.getSideLengthC();

	if (figure.getHaveFourSides()){

		std::cout << ", d = " << figure.getSideLengthD() << std::endl;
	}
	else { std::cout << std::endl; }

	std::cout << "Углы:";
	std::cout << " А = " << figure.getAngleA() << ", В = " << figure.getAngleB() << ", С = " << figure.getAngleC();
	if (figure.getHaveFourSides()) { std::cout << ", D = " << figure.getAngleD() << std::endl; }
	else { std::cout << std::endl; }
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	printFigure(Triangle1);

	rightTriangle rightTriangle1(10, 20, 30, 50, 60);
	printFigure(rightTriangle1);

	isoscelesTriangle isoscelesTriangle1(10, 20, 50, 60);
	printFigure(isoscelesTriangle1);

	equilateralTriangle equilateralTriangle1(30);
	printFigure(equilateralTriangle1);

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	printFigure(Quadrilateral1);

	Rectangle Rectangle1(10, 20);
	printFigure(Rectangle1);

	Square Square1(20);
	printFigure(Square1);

	Parallelogram Parallelogram1(20, 30, 30, 40);
	printFigure(Parallelogram1);

	Rhomb Rhomb1(30, 30, 40);
	printFigure(Rhomb1);

	return 0; system("pause");
}
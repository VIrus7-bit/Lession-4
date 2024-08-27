#include <iostream>
#include <string>

class Figure {
	protected:
	int numberOfSides_ = 0;
	std::string nameOfFigure_;

	public: Figure() : Figure(0, "Фигура") {};
			Figure(int numberOfSides, std::string nameOfFigure) : numberOfSides_{ numberOfSides }, nameOfFigure_{ nameOfFigure } {}

	int getNumberOfSides()	       { return numberOfSides_; } 
	std::string getNameOfFigure()  { return nameOfFigure_ ; } 
};

class Triangle : public Figure{

	public: Triangle() : Figure(3, "Треугольник") {};
};

class Quadrilateral : public Figure{

	public: Quadrilateral() : Figure(4, "Четырехугольник") {};
};

void print(Figure& P_Figure){

	std::cout << P_Figure.getNameOfFigure() << ": " << P_Figure.getNumberOfSides() << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian"); system("chcp 1251");

	std::cout << std::endl << "Количество сторон: " << std::endl;

	Figure Figure;
	print(Figure); 

	Triangle Triangle;
	print(Triangle);   

	Quadrilateral Quadrilateral;
	print(Quadrilateral);

	system("pause");
};
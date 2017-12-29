#include <stdio>
/* Code blocks example */

//A variable here is a global variable, its scope accesible on every part of the code
int global = 0;

void alterGlobal(int new_val) {
	std::cout << "Global variable old value: " << global << std::endl;
	global = new_val;	//the "new_val" variable is only visible inside this block...
	std::cout << "New value of global: " << global << std::endl;
}

void localVar() {
	int x = 0;	//this will be accesible everywhere inside the "localVar" function...
	
	if (x < 20) {
		int y = x + 3;	//"y" variable will be accesible only inside this "if..." statement, but "x" is accesible...
		for (int z = 0; z < y; z++) {
			std::cout << "The counter is: " << z << std::endl;	//"z" is declared inside the "for" loop, and is visible only inside the loop
			int x = 99;		//some compilers and languages admint this, and this will override the previous declaration of "x" but only inside this block
		}
	}
}

int main (int argc, char** argv) {
	alterGlobal(12);
	localVar();
	{
		//ADVANCED: you can create a block without any "if", "for", "while" statement or function declaration, and the same rules will apply
		int a = 0;	//this will be only visible inside this block
		a++;
	}
	//if I try to access "a" variable here, I'll get an error
	std::cout << "Variable outside block: " << a << std::endl;	//this will cause a compiler error...
}

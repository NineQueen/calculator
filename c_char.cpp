#include "c_char.h"
c_char::c_char(char ch){
		this_char = ch;
		//¿‡–Õ 
		type = -1;
		switch(ch){
				case '+':
					type = 0;
					break;
				case '-':
					type = 1;
					break;
				case '*':
					type = 2;
					break;
				case '/':
					type = 3;
					break;
				case '^':
					type = 4;
					break;
				case '!':
					type = 5;
					break;
				case '(':
					type = 6;
					break;
				case ')':
					type = 7;
					break;
				case '\0':
					type = 8;
					break;
				case '%':
					type = 9;
					break;
				case '@':
					type = 10;
				default:
					throw "”Ôæ‰¥ÌŒÛ!";
					break;
			}	
}

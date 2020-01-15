#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<stack>
#include "c_char.h"
using namespace std;
char pri[10][10]={
//顶   前+  -   *   /   ^   !   (   )   \0   %
/* + */	'>','>','<','<','<','<','<','>','>','<',
/* - */	'>','>','<','<','<','<','<','>','>','<',
/* * */ '>','>','>','>','<','<','<','>','>','<',
/* / */ '>','>','>','>','<','<','<','>','>','<',
/* ^ */ '>','>','>','>','>','<','<','>','>','<',
/* ! */ '>','>','>','>','>','>','#','>','>','<',
/* ( */ '<','<','<','<','<','<','<','=','#','<',
/* ) */ '#','#','#','#','#','#','#','#','#','#',
/* \0*/ '<','<','<','<','<','<','<','#','=','<',
/* % */ '>','>','>','>','>','>','#','>','>','>'
};
int main(){
	while(true){
		string s;
		int last=-2;
		int point = 0;	
		stack<float> snum;
		stack<c_char> schar;
		try{
			cin >> s;
			stack<float> snum;
			stack<c_char> schar;
			c_char end('\0');
			schar.push(end);
			while(point<=s.length()){
				if('0'<=s[point]&&s[point]<='9'){
					if(last==point-1){
						int a = snum.top();
						snum.pop();
						snum.push(a*10+s[point]-'0');
					}else{
						snum.push(s[point]-'0');
						if(snum.top()==0){
							throw 0;
						}
					}
					last = point;
				}else{
					c_char now(s[point]);
					switch(pri[schar.top().type][now.type]){
						case '<':
							schar.push(now);
							break;
						case '=':
							schar.pop();
							break;
						case '>':
							while(pri[schar.top().type][now.type]=='>'){
								int q = snum.top();
								snum.pop();
								int b;
								switch(schar.top().type){
									case 0:
										b = snum.top();
										snum.pop();
										snum.push(q+b);
										break;
									case 1:
										b = snum.top();
										snum.pop();
										snum.push(b-q);
										break;
									case 2:
										b = snum.top();
										snum.pop();
										snum.push(q*b);
										break;
									case 3:
										b = snum.top();
										snum.pop();
										snum.push(b/q);
										break;
									case 4:
										b = snum.top();
										snum.pop();
										snum.push(pow(b,q));
										break;
									case 5: 
										b = 1;
										for(int i =1;i<=q;i++){
										b = b*i;
										}
										snum.push(b);
										break;
									case 9:
										b = snum.top();
										snum.pop();
										snum.push(b%q);
										break;
									case 6:
									case 7:
									case 8:
										break;
									}
								schar.pop();
								if(schar.top().type==6)
									schar.pop(); 
							}
							if(now.this_char!=')'){
								schar.push(now);
							}
						}
					}
				point++;
			}
			cout << snum.top()<<endl;
			system("PAUSE");	
		}catch(const char* msg){
			cout << msg;
			char a;
			cin >> a;
			if(a=='#'){
				continue;
			}else{
				break;
			}
		}catch(int m){
			cout << "除数不能为0";
			continue;
		}
	}
	return 0;
} 

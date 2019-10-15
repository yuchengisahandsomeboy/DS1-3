// 10727249林恆毅 10727223陳宇呈 
#include <cstdlib>
#include<stdio.h>
#include<iostream>
#include<vector> 
#include<string >
using namespace std;
typedef char Str100[ 100 ] ;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Struct{
  public:
   string num;
   Struct * next;
} ; // Struct


class Stack
{
public:
    Struct * topPtr = NULL  ;
Stack() {
  topPtr = NULL ;
}

Stack( Struct * pointer  ) {
  topPtr = NULL ;
  copyInsert( topPtr, pointer ) ;
}

void copyInsert( Struct *& newPtr, Struct * pointer ) {
  if ( pointer != NULL ) {
    newPtr = new Struct() ;
    newPtr->num = pointer->num ;
    newPtr->next = NULL ;
    copyInsert( newPtr->next, pointer->next ) ;
  } // if
} // copyInsert()

void push( string & newItem) { //新增 
      Struct *newPtr = new Struct; 
	  newPtr->num = newItem; 
	  newPtr->next = topPtr; 
	  topPtr = newPtr ; 
} // push
string getTop() {  // 擷取 
 if ( !isEmpty() ) {
   return topPtr->num ; 
 } // if
  return " " ;
 } // end getTop
string pop() { 
   if ( !isEmpty() ) { 
     string top = topPtr->num; 
     Struct *temp = topPtr; 
     topPtr = topPtr->next; 
     temp->next = NULL; 
     delete temp; 
     return top ;
  } // end if 
} // end pop // 擷取後移除 

void pop1() { 
   if ( !isEmpty() ) { 
     Struct *temp = topPtr; 
     if( topPtr->next != NULL )
      topPtr = topPtr->next; 
     else { 
       temp->next = NULL; 	
       delete temp;  
	   topPtr == NULL ;
     } // else
     temp->next = NULL; 
     delete temp; 
  } // end if 
} // end pop // 擷取後移除 
bool isEmpty() {
        if ( topPtr == NULL ) 
         return true ;
        else 
          return false ;
} // isEmpty()

}; // end Stack

  void Number( string & case2, char & ch ) { 
    int i = 0 ;
    case2 = case2 + ch ;
    scanf( "%c", &ch ) ;
    while( ch >= '0' && ch <= '9' )  {
        case2 = case2 + ch ;
       scanf( "%c", &ch ) ;
     } // while 
 } // Number()
void Othertype( string & case1 ) {  
    char ch = '\0' ;
    int i = 0 ;
      scanf( "%c", & ch) ;
      case1 = case1 + ch ;
} // Othertype
void GetToken( string & testStr,vector<string> & Sentance ) {  
int i = 0 ;
string temp ;
int len = testStr.length() ;
for( i = 0 ; i < len ; i++ ) {
  if( testStr[i] == ' ' ) {
  while( testStr[i] == ' ' )
    i++ ;
  i-- ;
} // if
else if( testStr[i] >= '0' && testStr[i] <= '9' ) {
    while( testStr[i] >= '0' && testStr[i] <= '9' ) {
      temp = temp + testStr[i] ;
      i++ ;
    } // while 
    Sentance.push_back( temp )  ;
    i-- ;
  } // if
  else {
    temp = temp + testStr[i] ;
    Sentance.push_back( temp )  ;
   } // else
  temp = "";
} // for 

} // GetToken()
  
void GetToken1( string & testStr,vector<string> & Sentance ) {  
int i = 0 ;
string temp ;
int len = testStr.length()-1;
for( i = 0 ; len >= i ; len-- ) {
  if( testStr[len] == ' ' ) {
  while( testStr[len] == ' ' )
    len-- ;
  len++ ;
} // if
else if( testStr[len] >= '0' && testStr[len] <= '9' ) {
    while( testStr[len] >= '0' && testStr[len] <= '9' ) {
      temp = temp + testStr[len] ;
      len-- ;
    } // while 
    Sentance.push_back( temp )  ;
    len++ ;
  } // if
  else {
    temp = temp + testStr[len] ;
    Sentance.push_back( temp )  ;
   } // else
  temp = "";
} // for 


} // GetToken1()

void Checkerror( vector<string> Sentance, bool & check ) {
  int i = 0 ;
  int count = 0 ; 
  bool have = false ;
  while(  i < Sentance.size()  ) {
    if ( Sentance[i] == "(" ) {
      count++ ;
    } // if
    else if( Sentance[i] == ")" ) {
      count-- ;
    } // else if
    i++ ;
  } // while
  if( count > 0 ) {
    cout << "Error 2: there is one extra open parenthesis." << endl ;
    have = true ;
    check = true ;
  } // if
  else if( count < 0) {
    cout << "Error 2: there is one extra close parenthesis." << endl ; 
    have = true ; 
    check = true ;
  } // else if
  i = 0 ;
  while( i < Sentance.size() && have == false  ) {
    if ( Sentance[i] == ">" || Sentance[i] == "<" || Sentance[i] == "=" ||
	     Sentance[i] == "!" || Sentance[i] == "?" || Sentance[i] == "&" || 
		  Sentance[i] == "|" || Sentance[i] == "^"||  Sentance[i] == "."||  Sentance[i] == "," || 
		   Sentance[i] == "[" || Sentance[i] == "]" ||  Sentance[i] == "{" ||  Sentance[i] == "}"  ||
		    Sentance[i] == ":" || Sentance[i] == ";" || Sentance[i] == "#" || Sentance[i] == "'" ) {
      cout << "Error 1: " << Sentance[i] << "is not a legitimate character." << endl ;
      check = true ;
      break ;
      } // if 
    else if( Sentance[i] == "+" ||  Sentance[i] == "-" ||  Sentance[i] == "*" ||  Sentance[i] == "/") {
      if( i + 1 < Sentance.size() && ( Sentance[i+1] == "+" || Sentance[i+1] == "-" || Sentance[i+1] == "*" || Sentance[i+1] == "/") ) {
        cout << "Error 3: there is one extra operator." << endl ;
        check = true ;
        break ;
      } // if
	} // else if
	else if( Sentance[i] == ")" ) {
	  if( i + 1 < Sentance.size() && Sentance[i+1][0] >= '0' && Sentance[i+1][0] <= '9' ) { 
        cout << "Error 3: there is one extra operator." << endl ;
        check = true ;
        break ;
      } // if	    
    } // else if
    else if( Sentance[i] == "(" ) {
	  if( i + 1 < Sentance.size() && Sentance[i+1] == ")" ) { 
        cout << "Error 3: it is not infix in the parentheses." << endl ;
        check = true ;
        break ;
      } // if	
     } // else if  
    else if( Sentance[i][0] >= '0' && Sentance[i][0] <= '9' ) {
	  if( i + 1 < Sentance.size() && Sentance[i+1] == "(" ) { 
        cout << "Error 3: it is not infix in the parentheses." << endl ;
        check = true ;
        break ;
      } // if	
     } // else if  
    i++ ;
} // while  

  if( !check )
    cout << "It is a legitimate infix expression." << endl ;

} // Checkerror

 void InsertToken( Struct *& head, vector<string> Sentance, int & i ) { 
 
   Struct * walk = NULL ;
   Struct * temp = NULL ;
   walk = head ;
   walk -> num = Sentance[i] ; 
   if ( i < Sentance.size()-1 ) { 
     walk->next = new Struct ;
     walk = walk->next ;
     walk->next = NULL ;
     i++ ;
     InsertToken( walk , Sentance, i  ) ;
   } // if
   
   
  } // InsertToken.
  

int main(int argc, char** argv) {
   char ch = '\0' ;
   int command = 0 ;
   char g[100] ; 
   bool have = false ;
   bool check = false ;
   vector<string> Sentance  ;
      cout << endl << "**** 計算機 *****";
      cout << endl << "* 0. Quit *";
      cout << endl << "* 1. One  *";
      cout << endl << "* 2. More  *";
      cout << endl << "* 3. More  *";
      cout << endl << "*******************************";
      cout << endl << "Input a command(0, 1, 2,3 ): ";	 
      cin >> command ;
      cout << endl ;
	while( command != 0 ) {
      string testStr = "" ;
      int i = 0 ;  
      Struct * pointer = NULL ;
      Struct * temp1 = NULL ;
      bool check = false ;
	  if( command == 1 ) {
        cout << "Input an infix expression:" ;
        cin.get( ch ) ;
        cin.get( ch ) ;       
        while(  ch != '\n' ) {
          testStr += ch ;   
          cin.get( ch ) ;
	   } // while
	  	GetToken( testStr, Sentance ) ;
        Checkerror( Sentance, check ) ; // 
      } // if
      else if ( command == 3 ) {
      	string tempStr = "" ;
        cout << "Input an infix expression:" ;
        cin.get( ch ) ;
        cin.get( ch ) ;       
        while(  ch != '\n' ) {
          testStr += ch ;   
          cin.get( ch ) ;
	   } // while
	  	GetToken1( testStr, Sentance  ) ;
        Checkerror( Sentance, check ) ; 
    	if( check == false )  {	
        pointer = new Struct ;
        pointer-> next = NULL ;
        InsertToken( pointer, Sentance, i ) ;
        Stack inToPostfix;
          while( pointer != NULL  ) {
           if( pointer-> num[0] >= '0' && pointer -> num[0] <= '9'  ) { //是數字直接印 
             tempStr += pointer-> num+"," ; 
	     } // if  
        if( pointer-> num == ")" )
          inToPostfix.push( pointer-> num ) ; // 把+或-丟進去     
	    if( pointer-> num == "+" || pointer-> num == "-" ) { 
	   	  if( inToPostfix.getTop() == "*" || inToPostfix.getTop() == "/" ) {
             tempStr += inToPostfix.pop()+"," ; 
           inToPostfix.push( pointer-> num ) ; // 把+或-丟進去 
	     } // if
	     else if( inToPostfix.getTop() == "+" || inToPostfix.getTop() == "-" ) {
             tempStr += inToPostfix.pop()+"," ; 
           inToPostfix.push( pointer-> num ) ; // 把+或-丟進去 
	     } // else if
       } // if 
	   if( pointer-> num == "(" )  { 
	     while( inToPostfix.topPtr-> num != ")" )  { 
             tempStr += inToPostfix.pop()+"," ; 
         } // while 
         inToPostfix.pop() ; //把左括號移除 
       } // if 
       if( pointer-> num == "*" || pointer-> num == "/" ) {
	     if( inToPostfix.getTop() != " " && ( inToPostfix.getTop() == "+" || inToPostfix.getTop() == "-" ) ) {
           inToPostfix.push( pointer-> num ) ; // 把*或/丟進去
	      } // if 
          else if( inToPostfix.getTop() != " " && ( inToPostfix.getTop() == "*" || inToPostfix.getTop() == "/") ) {
            tempStr += inToPostfix.pop()+"," ; 
           inToPostfix.push( pointer-> num ) ; // 把*或/丟進去 
	      } // else if
       } // if
      if( pointer-> num == "*" || pointer-> num == "/" || pointer-> num == "+" || pointer-> num == "-"  ) {
        if(  inToPostfix.getTop() == " " ) {
          inToPostfix.push( pointer-> num ) ;
        } // if 
      } // if
      if( pointer-> num == "+" || pointer-> num == "*" || pointer-> num == "/" || pointer-> num == "-" ) {
        if( inToPostfix.getTop() == ")" ) 
          inToPostfix.push( pointer-> num ) ;
      } // if
      if( pointer-> next == NULL )
      while( inToPostfix.getTop() != " " )
       tempStr += inToPostfix.pop()+"," ; 
       pointer = pointer-> next ;
    } // while    
	Struct * temp = pointer ;
    while( pointer != NULL ){	
      temp = pointer ;
      pointer = pointer-> next ;
      delete temp ;
	} // while 	
	delete temp ;
   }// if
   cout << tempStr  ; 
} // else if 
else if ( command == 2 ) { //前序 
        cout << "Input an infix expression:" ;
        cin.get( ch ) ;
        cin.get( ch ) ;       
        while(  ch != '\n' ) {
          testStr += ch ;   
          cin.get( ch ) ;
	   } // while
	  	GetToken( testStr, Sentance  ) ;
        Checkerror( Sentance, check ) ; 
    	if( check == false )  {	
        pointer = new Struct ;
        pointer-> next = NULL ;
        InsertToken( pointer, Sentance, i ) ;
        Stack inToPostfix;
         temp1 = pointer ;
          while( pointer != NULL  ) {
           if( pointer-> num[0] >= '0' && pointer -> num[0] <= '9'  ) { //是數字直接印 
          cout << pointer-> num << "," ; 
	     } // if  
        if( pointer-> num == "(" )
          inToPostfix.push( pointer-> num ) ; // 把+或-丟進去     
	    if( pointer-> num == "+" || pointer-> num == "-" ) { 
	   	  if( inToPostfix.getTop() == "*" || inToPostfix.getTop() == "/" ) {
             cout << inToPostfix.pop() << " " ; // 映出符號 
           inToPostfix.push( pointer-> num ) ; // 把+或-丟進去 
	     } // if
	     else if( inToPostfix.getTop() == "+" || inToPostfix.getTop() == "-" ) {
           cout << inToPostfix.pop() << " " ; // 映出符號 
           inToPostfix.push( pointer-> num ) ; // 把+或-丟進去 
	     } // else if
       } // if 
	   if( pointer-> num == ")" )  { 
	     while( inToPostfix.topPtr-> num != "(" )  { 
	       cout << inToPostfix.pop() << ","  ; 
         } // while 
         inToPostfix.pop() ; //把左括號移除 
       } // if 
       if( pointer-> num == "*" || pointer-> num == "/" ) {
	     if( inToPostfix.getTop() != " " && ( inToPostfix.getTop() == "+" || inToPostfix.getTop() == "-" ) ) {
           inToPostfix.push( pointer-> num ) ; // 把*或/丟進去
	      } // if 
          else if( inToPostfix.getTop() != " " && ( inToPostfix.getTop() == "*" || inToPostfix.getTop() == "/") ) {
	       cout << inToPostfix.pop() << "," ;
           inToPostfix.push( pointer-> num ) ; // 把*或/丟進去 
	      } // else if
       } // if
      if( pointer-> num == "*" || pointer-> num == "/" || pointer-> num == "+" || pointer-> num == "-"  ) {
        if(  inToPostfix.getTop() == " " ) {
          inToPostfix.push( pointer-> num ) ;
        } // if 
      } // if
      if( pointer-> num == "+" || pointer-> num == "*" || pointer-> num == "/" || pointer-> num == "-" ) {
        if( inToPostfix.getTop() == "(" ) 
          inToPostfix.push( pointer-> num ) ;
      } // if
      if( pointer-> next == NULL )
      while( inToPostfix.getTop() != " " )
        cout << inToPostfix.pop() ;
       pointer = pointer-> next ;
    } // while    
	Struct * temp = pointer ;
    while( pointer != NULL ){	
      temp = pointer ;
      pointer = pointer-> next ;
      delete temp ;
	} // while 	
	delete temp ;
   }// if
} // else if 
else 
    cout << "Command does not exist!" << endl ;
      Sentance.clear() ;
      cout << endl << "**** 計算機 *****";
      cout << endl << "* 0. Quit *";
      cout << endl << "* 1. One  *";
      cout << endl << "* 2. More  *";
      cout << endl << "* 3. More  *";
      cout << endl << "*******************************";
      cout << endl << "Input a command(0, 1, 2, 3): ";	 
	  cin >> command ;
      cout << endl ;
} // while 

} // main

#In this project we tried to solve this problem by using ‘c++’. 
#In regular calculator, there has only infix process. 
#But in this project we can use both infix and postfix process.



#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <windows.h>

using namespace std;
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef long long int ll;

/*** Functions ***/
bool Digit(char C);
bool Operator(char C);
bool Operator(char C);
int prec(char C);
void init();
void Addition();
void Substraction();
void Multiplication();
void Division();
void Calculator(char C);
void postFixOpp(string str1);
void postFix();
void inFix();
/*** Functions ***/


stack<ll>Stack;
string str;

void init()
{
    while (!Stack.empty())
        Stack.pop();
}

void Addition()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1+op2;
    Stack.push(S);
}

void Substraction()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1-op2;
    Stack.push(S);
}

void Multiplication()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1*op2;
    Stack.push(S);
}

void Division()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    if (op2)
    {
        op1=Stack.top();
        Stack.pop();
        S=op1/op2;
        Stack.push(S);
    }
    else
        cout << "\n\tWrong equation!!!\n\n\tInput Correctly Again...\n\n";
}
void Calculator(char C)
{
    if (C=='+')
        Addition();
    else if (C=='-')
        Substraction();
    else if (C=='*')
        Multiplication();
    else if (C=='/')
        Division();
}

bool Digit(char C)
{
    if(C>='0' && C<='9')
        return true;
    return false;
}

bool Operator(char C)
{
    if(C=='+' || C=='-' || C=='*' || C=='/')
        return true;
    return false;
}

int prec(char C)
{
    if(C=='*' || C=='/')
        return 2;
    else if(C=='+' || C=='-')
        return 1;
    else
        return -1;
}

void postFixOpp(string str1)
{
    int l=str1.length();
    for(int i=0; i<l; i++)
    {
        if(str1[i]==' ')
            continue;

        if(Operator(str1[i]))
            Calculator(str1[i]);

        else if(Digit(str1[i]))
        {
            ll opp=0;
            while(i<l && Digit(str1[i]))
            {
                opp=(opp*10)+(str1[i]-'0');
                i++;
            }
            i--;
            Stack.push(opp);
        }
    }
    cout << "\n\tResult: " << Stack.top() << endl << endl;
}

void postFix()
{
    printf("\nEnter The PostFix Equation: ");
    cin.ignore();
    getline(cin,str);
    postFixOpp(str);
}

void inFix()
{
    stack<char> st;
    string ns;

    printf("\nEnter The inFix Equation: ");
    cin.ignore();
    getline(cin,str);

    st.push('N');
    int l=str.length();
    for(int i=0; i<l; i++)
    {
        if(Digit(str[i]))
            ns+=str[i];

        else if (str[i]==' ')
            ns+=' ';

        else if(str[i]=='(')
            st.push('(');

        else if(str[i]==')')
        {
            while(st.top()!='N' && st.top()!='(')
            {
                ns+=st.top();
                st.pop();
            }
            if(st.top()=='(')
                st.pop();
        }
        else
        {
            while(st.top()!='N' && prec(str[i])<=prec(st.top()))
            {
                ns+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(st.top()!='N')
    {
        ns+=st.top();
        st.pop();
    }
    postFixOpp(ns);
}

int main()
{
    system("Color 70");
    int choice,j=1;
    for (int i=1; i<=j; i++)
    {
        init();
        cout << "\n\n\tEnter Your Expression:\n"
             << "\t\t1 for infix\n"
             << "\t\t2 for postfix\n"
             << "\tEnter Choice: ";
        cin >> choice;
        if(choice==1)
            inFix();
        else if(choice==2)
            postFix();
        else
            cout << "\n\n\t****Wrong Choice**** \n\n";

        cout << "Do you want to continue??? y/n: ";
        char C;
        cin >> C;
        if(C=='y' || C=='Y')
            j++;
    }
}
 
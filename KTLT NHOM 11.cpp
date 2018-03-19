#include<bits/stdc++.h>
using namespace std;
string s;
struct Node{
	int value;
	Node* p[26];// luu 26 con tro ung voi 26 chu cai thuong
	bool checkVo;// kiem tra xem da ket thuc 1 tu chua
};typedef Node Node;
  typedef Node* Tree;

void Init_Tree(Tree &tr){
	tr=NULL;
}
Node* CreatNode(int k){
Node*p =new Node;
	for(int i=0;i<26;i++) p->p[i]=NULL;
	return p;
}

void Insert(Tree &tr,int k){
int x= s[k]-'a';
Node*q=tr;
	if(k==s.length())  return;	
	if(q->p[x]==NULL)
		q->p[x]=CreatNode(k);
	if(k==s.length()-1) q->p[x]->checkVo=true;
		Insert(q->p[x],k+1);
}

bool Check(Tree &tr,int k){
int x=s[k]-'a';	

		if(tr->p[x]!=NULL) 
			if(k==s.length()-1 and tr->p[x]->checkVo==true) return true ;else Check(tr->p[x],k+1);
		 else
		return false;

}
Tree tree;
void Input(){
Init_Tree(tree);
tree=CreatNode(0);
	ifstream cin1("dictionary.txt");
	while(!cin1.eof()){
		cin1>>s;
		Insert(tree,0);
	}

}

main(){
Input();
}


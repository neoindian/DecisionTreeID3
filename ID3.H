#ifndef __ID3_LEARNING_H__
#define __ID3_LEARNING_H__


#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<list>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include<sstream>
using namespace std;
enum Sex
{
 M,
 F
};

enum Breed
{
  P,
  PB ,
  AS ,
  C
};
enum Decision
{
 N,
 Y
};

enum Attribute
{
  Age,
  Sex,
  Breed
};

enum NodeType
{
  NotLeaf,
  Leaf 
};

class ID3
{
  public:
  int at_;
  int numOfChildNodes_;
  NodeType nt_;  
  vector<int> attrList_;
  string nodeLabel_;
  ID3 * parent_; 
  ID3 *  childNodes_[4];
  string childLabels_[4];
  ID3()
  {
    numOfChildNodes_=0;
    for(int i=0;i<4;i++)
    {
       childNodes_[i]=NULL;
       childLabels_[i]="";
    }
  }
};

double calculateOverAllEntropy(int data[][4],int size);
double calculateEntropy(int numY,int numN);
double calculateGain(Attribute at,double ent,int data[][4],int size,int &leafType);
void findDistribution(Attribute at,int val,int & numY,int &numN,int data[][4],int size);

void calculatePerAttributeGain(Attribute at,int Values[],double ent,int data[][4],int datasize,int atSize,double & gain,int & leafType);

ID3 * createID3TreeNode(int at,NodeType ndt,string nodelabel,string parentLabel,ID3 * parent);
void createID3R(ID3 * parent,int at, int data[][4],int size,vector<Attribute> attributeList,string parentLabel);

void printNode(ID3 * node,bool nodeCreated,string nodeStr);
void attrToName(int at,string & atName);
void calculateLeafDecision(int data[][4],int datasize,int &leafType);
void mapParentAttrChildAttr(int atV, int childAtv,string & name);
void flushToFile(const string fileName);

#endif

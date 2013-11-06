// #!/bin/bash
// /../bin/ls > /dev/null
// # BEGIN BASH SCRIPT
// printf "//" | cat - $0 | g++ -g -liglxml -ligl -ltinyxml2 -I/opt/local/include/eigen3 -L$LIBIGL/external/tinyxml2 -I$LIBIGL/external/tinyxml2 -I$LIBIGL/include -L$LIBIGL/lib -o .main -x c++ - && ./.main $@
// rm -f .main
// # END BASH SCRIPT
// exit


#include "XMLSerializer.h"


/*
Use the following lines to run the XMLSerializer tests:
igl::XMLSerializerTest* test = new igl::XMLSerializerTest();
bool success = test->Test();
delete test;
*/
bool igl::XMLSerializerTest::Test()
{
  // test vars 0
  char testChar0 = 'a';
  char* testCharArray0 = "testCharArray0";
  std::string testString0 = "testString0";
  bool testBool0 = true;
  unsigned int testUnsigned0 = 13;
  int testInt0 = 1000;
  float testFloat0 = 0.00001f;
  double testDouble0 = 0.01000000005;

  //std::array<float,2> testArray0 = {{0.001f,1.001f}};

  std::pair<int,bool> testPair0;
  testPair0.first = 5;
  testPair0.second = true;

  std::vector<int> testVector0;
  testVector0.push_back(1);
  testVector0.push_back(2);
  testVector0.push_back(3);

  Eigen::Matrix3i testDenseMatrix0;
  //testDenseMatrix0 = Eigen::Matrix3i::Identity();

  Eigen::SparseMatrix<double> testSparseMatrix0(3,3);
  std::vector<Eigen::Triplet<double> > triplets;
  triplets.push_back(Eigen::Triplet<double>(0,0,1));
  triplets.push_back(Eigen::Triplet<double>(1,1,2));
  triplets.push_back(Eigen::Triplet<double>(2,2,3));
  testSparseMatrix0.setFromTriplets(triplets.begin(),triplets.end());

  igl::XMLSerializerTest* testObject0 = new igl::XMLSerializerTest();

  std::vector<std::pair<int,bool>*> testComplex10;
  testComplex10.push_back(&testPair0);
  testComplex10.push_back(&testPair0);

  std::vector<igl::XMLSerializerTest*> testComplex20;
  testComplex20.push_back(testObject0);
  testComplex20.push_back(testObject0);
  
  // test vars 1
  char testChar1 = 'b';
  char* testCharArray1 = "testCharArray1";
  std::string testString1 = "testString1";
  bool testBool1 = false;
  unsigned int testUnsigned1 = 12;
  int testInt1 = -1000;
  float testFloat1 = -0.00001f;
  double testDouble1 = -0.000000000001;

  //std::array<float,2> testArray1 = {{-0.001f,-1.001f}};

  std::pair<int,bool> testPair1;
  testPair1.first = -5;
  testPair1.second = false;

  std::vector<int> testVector1;
  testVector1.push_back(-1);
  testVector1.push_back(-2);
  testVector1.push_back(-3);

  Eigen::Matrix3i testDenseMatrix1;
  //testDenseMatrix1 = Eigen::Matrix3i::Identity();
  //testDenseMatrix1 *= 2;

  Eigen::SparseMatrix<double> testSparseMatrix1(3,3);
  triplets.clear();
  triplets.push_back(Eigen::Triplet<double>(0,0,-1));
  triplets.push_back(Eigen::Triplet<double>(1,1,-2));
  triplets.push_back(Eigen::Triplet<double>(2,2,-3));
  testSparseMatrix1.setFromTriplets(triplets.begin(),triplets.end());

  igl::XMLSerializerTest* testObject1 = new igl::XMLSerializerTest();
  testObject1->testInt = 3;
  testObject1->testVector.clear();

  std::vector<std::pair<int,bool>*> testComplex11;
  testComplex11.push_back(&testPair1);
  testComplex11.push_back(&testPair1);

  std::vector<igl::XMLSerializerTest*> testComplex21;
  testComplex21.push_back(testObject1);
  testComplex21.push_back(testObject1);
  
  // test Serializer
  bool testResult = true;
  
  // test static functions
  
  // check static updating
  int testInt = 5;
  testResult &= igl::XMLSerializer::SaveObject(testInt0,"test.xml");
  testResult &= igl::XMLSerializer::SaveObject(testChar0,"testChar","test","test.xml",false);
  testResult &= igl::XMLSerializer::LoadObject(testInt,"test.xml");
  testResult &= testInt0 == testInt;

  // check static overwriting
  testInt = 3;
  testResult &= igl::XMLSerializer::SaveObject(testInt0,"test.xml");
  testResult &= igl::XMLSerializer::SaveObject(testChar0,"testChar","test","test.xml",true);
  testResult &= igl::XMLSerializer::LoadObject(testInt,"test.xml") == false;
  testResult &= testInt0 != testInt;

  // check static based type saving
  testResult &= igl::XMLSerializer::SaveObject(testChar0,"testChar","test0","test.xml",true);
  testResult &= igl::XMLSerializer::SaveObject(testCharArray0,"testCharArray","test0","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testString0,"testString","test0","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testBool0,"testBool","test0","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testUnsigned0,"testUnsigned","test0","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testInt0,"testInt","test0","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testFloat0,"testFloat","test0","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testDouble0,"testDouble","test0","test.xml",false);
  //testResult &= igl::XMLSerializer::SaveObject(testArray0,"testArray","test1","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testPair0,"testPair","test1","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testVector0,"testVector","test1","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testDenseMatrix0,"testDense","test1","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testSparseMatrix0,"testSparse","test1","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testObject0,"testObject","test1","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testComplex10,"testComplex1","test1","test.xml",false);
  testResult &= igl::XMLSerializer::SaveObject(testComplex20,"testComplex2","test1","test.xml",false);

  testResult &= igl::XMLSerializer::LoadObject(testChar1,"testChar","test0","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testCharArray1,"testCharArray","test0","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testString1,"testString","test0","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testBool1,"testBool","test0","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testUnsigned1,"testUnsigned","test0","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testInt1,"testInt","test0","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testFloat1,"testFloat","test0","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testDouble1,"testDouble","test0","test.xml");
  //testResult &= igl::XMLSerializer::LoadObject(testArray1,"testArray","test1","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testPair1,"testPair","test1","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testVector1,"testVector","test1","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testDenseMatrix1,"testDense","test1","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testSparseMatrix1,"testSparse","test1","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testObject1,"testObject","test1","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testComplex11,"testComplex1","test1","test.xml");
  testResult &= igl::XMLSerializer::LoadObject(testComplex21,"testComplex2","test1","test.xml");

  testResult &= testChar0 == testChar1;
  testResult &= strcmp(testCharArray0,testCharArray1) == 0;
  testResult &= testString0 == testString1;
  testResult &= testBool0 == testBool1;
  testResult &= testUnsigned0 == testUnsigned1;
  testResult &= testInt0 == testInt1;
  testResult &= testFloat0 == testFloat1;
  testResult &= testDouble0 == testDouble1;
  /*for(unsigned int i=0;i<testArray0.size();i++)
    testResult &= testArray0[i] == testArray1[i];*/
  testResult &= testPair0.first == testPair1.first;
  testResult &= testPair0.second == testPair1.second;
  testResult &= testVector0.size() == testVector1.size();
  for(unsigned int i=0;i<testVector0.size();i++)
    testResult &= testVector0[i] == testVector1[i];
  testResult &= (testDenseMatrix0-testDenseMatrix1).sum() == 0;
  testResult &= (testSparseMatrix0-testSparseMatrix1).norm() == 0;
  testResult &= testObject0->testInt == testObject1->testInt;
  testResult &= testObject0->testVector.size() == testObject1->testVector.size();
  for(unsigned int i=0;i<testObject0->testVector.size();i++)
    testResult &= testObject0->testVector[i] == testObject1->testVector[i];
  testResult &= testComplex10.size() == testComplex11.size();
  for(unsigned int i=0;i<testComplex10.size();i++)
  {
    testResult &= testComplex10[i]->first == testComplex11[0]->first;
    testResult &= testComplex10[i]->second == testComplex11[0]->second;
  }
  testResult &= testComplex20.size() == testComplex21.size();
  for(unsigned int i=0;i<testComplex20.size();i++)
  {
    testResult &= ((XMLSerializerTest*)testComplex20[i])->testInt == ((XMLSerializerTest*)testComplex21[i])->testInt;
    testResult &= ((XMLSerializerTest*)testComplex20[i])->testVector.size() == ((XMLSerializerTest*)testComplex21[i])->testVector.size();
    for(unsigned int j=0;j<((XMLSerializerTest*)testComplex20[i])->testVector.size();j++)
       testResult &= ((XMLSerializerTest*)testComplex20[i])->testVector[j] == ((XMLSerializerTest*)testComplex21[i])->testVector[j];
  }

  igl::XMLSerializer* s = new igl::XMLSerializer("test0");

  // clear file
  testResult &= s->Save("test.xml",true);

  testResult &= s->Add(testChar0,"testChar");
  testResult &= s->Add(testCharArray0,"testCharArray");
  testResult &= s->Add(testString0,"testString");
  testResult &= s->Add(testBool0,"testBool");
  testResult &= s->Add(testUnsigned0,"testUnsigned");
  testResult &= s->Add(testInt0,"testInt");
  testResult &= s->Add(testFloat0,"testFloat");
  testResult &= s->Add(testDouble0,"testDouble");

  s->SetCurrentGroup("test1");

  //testResult &= s->Add(testArray0,"testArray");
  testResult &= s->Add(testPair0,"testPair");
  testResult &= s->Add(testVector0,"testVector");
  testResult &= s->Add(testDenseMatrix0,"testDenseMatrix");
  testResult &= s->Add(testSparseMatrix0,"testSparseMatrix");
  testResult &= s->Add(testObject0,"testObject");
  testResult &= s->Add(testComplex10,"testComplex1");
  testResult &= s->Add(testComplex20,"testComplex2");
  
  // Test single attribute save load
  testResult &= s->Save("testComplex2","test1","test.xml",true);
  testResult &= s->Load("testComplex2","test1","test.xml");
  
  testResult &= testComplex20.size() == testComplex21.size();
  for(unsigned int i=0;i<testComplex20.size();i++)
  {
    testResult &= ((XMLSerializerTest*)testComplex20[i])->testInt == ((XMLSerializerTest*)testComplex21[i])->testInt;
    testResult &= ((XMLSerializerTest*)testComplex20[i])->testVector.size() == ((XMLSerializerTest*)testComplex21[i])->testVector.size();
    for(unsigned int j=0;j<((XMLSerializerTest*)testComplex20[i])->testVector.size();j++)
        testResult &= ((XMLSerializerTest*)testComplex20[i])->testVector[j] == ((XMLSerializerTest*)testComplex21[i])->testVector[j];
  }

  // Test group save load without overriding
  testResult &= s->Save("test0","test.xml",false);
  testResult &= s->Load("test0","test.xml");
  testResult &= s->Load("testComplex2","test1","test.xml");

  testResult &= testChar0 == testChar1;
  testResult &= strcmp(testCharArray0,testCharArray1) == 0;
  testResult &= testString0 == testString1;
  testResult &= testBool0 == testBool1;
  testResult &= testUnsigned0 == testUnsigned1;
  testResult &= testInt0 == testInt1;
  testResult &= testFloat0 == testFloat1;
  testResult &= testDouble0 == testDouble1;

  // Test full serialization save load
  testResult &= s->Save("test.xml",true);
  testResult &= s->Load("test.xml");
  
  testResult &= testChar0 == testChar1;
  testResult &= strcmp(testCharArray0,testCharArray1) == 0;
  testResult &= testString0 == testString1;
  testResult &= testBool0 == testBool1;
  testResult &= testUnsigned0 == testUnsigned1;
  testResult &= testInt0 == testInt1;
  testResult &= testFloat0 == testFloat1;
  testResult &= testDouble0 == testDouble1;
  /*for(unsigned int i=0;i<testArray0.size();i++)
    testResult &= testArray0[i] == testArray1[i];*/
  testResult &= testPair0.first == testPair1.first;
  testResult &= testPair0.second == testPair1.second;
  testResult &= testVector0.size() == testVector1.size();
  for(unsigned int i=0;i<testVector0.size();i++)
    testResult &= testVector0[i] == testVector1[i];
  testResult &= (testDenseMatrix0-testDenseMatrix1).sum() == 0;
  testResult &= (testSparseMatrix0-testSparseMatrix1).norm() == 0;
  testResult &= testObject0->testInt == testObject1->testInt;
  testResult &= testObject0->testVector.size() == testObject1->testVector.size();
  for(unsigned int i=0;i<testObject0->testVector.size();i++)
    testResult &= testObject0->testVector[i] == testObject1->testVector[i];
  testResult &= testComplex10.size() == testComplex11.size();
  for(unsigned int i=0;i<testComplex10.size();i++)
  {
    testResult &= testComplex10[i]->first == testComplex11[0]->first;
    testResult &= testComplex10[i]->second == testComplex11[0]->second;
  }
  testResult &= testComplex20.size() == testComplex21.size();
  for(unsigned int i=0;i<testComplex20.size();i++)
  {
    testResult &= ((XMLSerializerTest*)testComplex20[i])->testInt == ((XMLSerializerTest*)testComplex21[i])->testInt;
    testResult &= ((XMLSerializerTest*)testComplex20[i])->testVector.size() == ((XMLSerializerTest*)testComplex21[i])->testVector.size();
    for(unsigned int j=0;j<((XMLSerializerTest*)testComplex20[i])->testVector.size();j++)
        testResult &= ((XMLSerializerTest*)testComplex20[i])->testVector[j] == ((XMLSerializerTest*)testComplex21[i])->testVector[j];
  }

  delete s;
  printf("done with test.\n");

  return testResult;
}

int main(int argc, char * argv[])
{
  igl::XMLSerializerTest test;
  return !test.Test();
}

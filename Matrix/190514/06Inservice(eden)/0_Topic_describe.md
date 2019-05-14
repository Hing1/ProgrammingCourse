# Inservice (eden)

## Description

Please complete the following 4 classes: Person, Student, Worker, Inservice.</br>
Note:</br>
Person owns data member name and sex, the output format is (For more detail, see the sample output):

```cpp
// you should add this ouput statement in the constructor
cout << "Construct Person" << endl;
// you should add this ouput statement in the destructor
cout << "Destruct Person" << endl;
```

Student is a derived class of Person, its data member is a string sno(Ñ§ºÅ), its constructor has to print "Construct Student" and its destructor has to print "Destruct Student"</br>
Worker is a derived class of Person, its data member is a string wno(Ö°Ô±ºÅ), its constructor has to print "Construct Worker" and its destructor has to print "Destruct Worker"</br>
Please think the relationship between InService and Student/Worker, and implement InService class by yourself. with its constructor prints "Construct InService" and its destructor prints "Destruct InService"</br>

## Sample Input

```cpp
amblpo
1
13154671
10814061
```

## Sample Output

```cpp
Construct Person
Construct Student
Construct Worker
Construct InService
amblpo
1
amblpo
1
13154671
amblpo
1
10814061
Destruct InService
Destruct Worker
Destruct Student
Destruct Person
```

## Hints

Virtual inheritance
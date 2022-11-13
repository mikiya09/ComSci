

# conda sqlite
```
>> conda actiavte "env"
>> conda install -c conda-forge ipython-sql
```



# Database Management System (DBMS)

### Basic Goals
```
[1] collect & store
[2] efficiently query 
[3] safely update
[4] design trade-offs
```

### Basic Concepts
#### [+] Definition
```
1) A large, integrated collection of data

2) Models a real-world enterprise

    + Entities (e.g. students, courses)
    + Relationships (e.g. Chris is enrolled in course 145) 

3) a piece of software designed to store and manage databases


                  ---                                               ---
    Students        |                          who takes what         |
    Courses         |-- Entities                                      |-- Relationships
    Professors      |                          who teaches what       |
                  ---                                               ---
```

#### [+] Data Model 
```
A data model is a collection of concepts for describing databases 
    
    + The relational model of data is the most widely used model today 
    + relation table
```

#### [+] Schema 
```
A schema is a description of a particular collection of data, using the given data model 

    + every relation in a relational data model has a schema describing types
```

##### &#x23f5; Logical Schema
```
Logical Schema 
    
    + Students  (sid: string, name: string, gpa: float)
    + Courses   (cid: string, cname: string, credits: int)
    + Enrolled  (sid: string, cid: string, grade: string)

    --------------------                                          -------------------------
    | sid | Name | gpa |                                          | cid | cname | credits |
    |-----|------|-----|                                          |-----|-------|---------|
    | 101 | Bob  | 3.2 |                                          | 564 | 564-2 |    4    |
    |-----|------|-----|                                          |-----|-------|---------|
    | 123 | Mary | 3.8 |            Corresponding Keys            | 308 | 417   |    2    |
    --------------------                                          -------------------------
      ^  Students                        Enrolled                   ^       Courses
      |                            ---------------------            |
      |                            | sid | cid | Grade |            |
      |                            |-----|-----|-------|            |
      |_________________________   | 123 | 564 |   A   |            |
                                   ---------------------            |
                                            |                       |
                                            |_______________________|

```

##### &#x23f5; Physical Schema 
```
1) Administrator Level 
2) describe data layout 
    + Relations as unordered files
    + Some data in sorted order (index)
```

##### &#x23f5; External Schema 
```
1) Application Level
2) Views
    + course_info (cid: string, enrollment: integer)
    + Derived from other tables
```

#### [+] Data Independence 
```
Applications do not need to worry about how the data is structure and stored 
```
##### &#x23f5; Logical Data Independence
```
Don't ask can we add a new entity or attribute without rewriting the applications 
: you can

>> protection from changes in the logical structure of the data
```
##### &#x23f5; Physical Data Independence
```
Don't ask which disks are the data stored on? Is the data indexed?
: you don't need to know 

>> protection from physical layout changes
```

#### [+] Key Concepts (challenges)
##### &#x23f5; Transaction & Atomicity 
```
1) Transaction (TXN): an atomic sequence of database actions (reads/writes)

2) Atomicity: an action either completes entirely or not at all
                                         --------    ----------

ex).                        _________________________________
Acct  |  Balance            |                               |              Acct  |  Balance 
----------------            | Transfer $3K from a10 to a20: |              ----------------
a10   |  20,000      -->    | 1. Debit $3k from a10         |    -->        a10  | 17,000
a20   |  15,000             | 2. Credit $3k to a20          |               a20  | 18,000
                            |_______________________________|
                                          (TXN)
                        

!! cautions: 
all instruction in the box is a TXN, while crash of DB could happen either 

    + before 1 
    + after 1 but before 2 
    + after 2 

because the properties of atomicity, 
whichever stage crash happen TXN result in not complete at all 
```
##### &#x23f5; Consistency 
```
1) An action results in a state which conforms to all integrity constraints

2) integrity constraints: 
> each course is assigned to exactly one room

3) Transactions leave the DB in a consistent state 
> however, note that DBMS does not understand the real meaning of the constraints consistency 
> burden is still on the user
```
##### &#x23f5; Locking (concurrency)
```
1) DBMS ensures that the execution of {T1, ... ,Tn} is equivalent to some serial execution 


2) Locking:
> before reading or writing, 
> transaction requires a lock from DBMS, holds until the end


3) If Ti wants to write to an item x and Tj wants to read x, then Ti, Tj conflict
> Solution via locking: 
    + only one winner gets the lock 
    + loser is blocked (waits) until winner finishes


4) Write-ahead Logging (WAL)
> keep a log of all the writes done 
> after a crash, the partially executed TXNs are undone using the log
```
### Relational Model
```
1) Relational Model is a precise, implementable procedural representation 
2) We can operate on it, and database maps internally into this procedural language
```
#### [+] Relational Schema 
<img src="./pic/relationalSchema.png" width=500>
<br>

```
A relational schema describes the data that is contained in a relational instance
```
#### [+] Relational Instance (Data)
```
A relational instance is a set of tuples(rows) all conforming to the same schema
```
##### &#x23fb; Columns
<img src="./pic/relationalColumns.png" width=500>
<br> 

##### &#x23fb; Rows
<img src="./pic/relationalRows.png" width=500>
<br>

```
Relational Algebra allows us to translate declarative (SQL) queries into precise and optimizable expressions
```
### Algebra 
```
simple version: operators and atomic operands (操作数)
```
```
1) A language based on operators and a domain of values. 
   Operators map values taken from the domain into other domain values.

2) When the domain is a set of all relations (and the operators are as described later),
   we get the relational algebra

3) We refer to the expression as a query and the value produced as the query result
```
#### [+] Arithmetic Algebra
```
1) operands are variables and constants
2) operators are the usual arithmetic operators 
ex).
(x+y)*2 or ((x+7)/(y-3)) + x
```
#### [+] Relational Algebra 
```
[!] Domain: set of relations -> relation = table 


[!] work flow:
                       ----------------
    -------------      | Relational   |      ---------------------      -------------
    | SQL Query |  ->  | Algebra (RA) |  ->  | Optimized RA Plan |  ->  | Execution |
    -------------      | Plan         |      ---------------------      -------------
                       ----------------
      declarive         translate to            find locally             Execute each
        query           RA expression           equivalent-but           operator of the 
                                                more efficient-RA        optimized plan
                                                expression

1) operands are variables that stand for relations and relations (sets of tuples)
2) RA operates on sets(multisets)
3) every attribute must have a unique name 
```
##### &#x23f5; Operations
```
1) Basic Operators (5)
   > select 
   > project  
   > union 
   > set difference
   > Cartesian product (cross product)
   
2) Derived Operators
   > intersection, complement
   > renaming: p
   > join (natural, equi-join, theta join)
```
##### &#x23f5; Classfication 
```
1) Operations that remove parts of relations:
    + selection 
    + project 

2) Operations that combine tuples from two relations:
    + Cartesian product
    + join 

3) Since each operation returns a relation 
    + operations can be composed
```

#### [+] Relational Query Languages 
```
Language for describing queries on a relational database 
```
##### &#x23f5; Structured Query Language (SQL)
```
1) Predominant application-level query language 
2) Declarative 
```
##### &#x23f5; Relational Algebra 
```
1) Intermediate language used within DBMS 
2) Procedural 
```
### RA Operators
#### [+] Select Operator
##### &#x03ec;<sub>condition</sub>(relation)
```
produce table containing subset of rows of argument table satisfying condition
                         --------------
```

<img src="./pic/selectOperator.png" width=600>
<br>

##### &#x23f5; Selection Condition 
<img src="./pic/selectionCondition.png" width=600>

#### [+] Project Operator 
##### &#x03c0;<sub>attribute_list</sub>(relation)
```
Produces table containing subset of columns of argument table
                          -----------------
```

<img src="./pic/projectOperator.png" width=600>

```
result is a table(relation) with no duplicates, it can have fewer tuples than the original
```

<img src="./pic/projectExample.png" width=600>

#### [+] Set Operator 

*Relation is a set of tuples, so set operations should apple: **&#x2229;, U,** ---(set different)*
```
1) result of combining two relations with a set operator is a relation => 
   all its elements msut be tuples having same structure 

2) meaning length of rows and columns must be the same, atrributes must be the same

3) Hence, scope of set operations limited to union compatible relations 
                                             --------------------------
```
##### &#x23f5; Union Compatible Relations 
```
Two relations are union compatible if 
    1) both have same number of columns 
    2) Names of atrributes are the same in both 
    3) Attributes with the same name in both relations have the same domain

reiterate: 
+ union compatible relations can be combined using union, intersection and set difference
```

##### &#x23fb; Example 
<img src="./pic/unionCompatibleExample.png" width=400>


#### [+] Cartesian Product 
```
If R and S are two relations, R x S is the set of all concantenated tuples <x, y> 
where x is a tuple in R and y is a tuple in S

1) R and S need not be union compatible 
2) but they must have distinct attribute names
|
3) Attributes of relation must have distinct names, which is not guranteed with Cartesian product
```
##### &#x23f5; Compute
```
expensive to compute
```

<img src="./pic/cartesianProduct.png" width=400>

##### *#x23f5; Renaming 
<img src="./pic/renaming.png" width=400>

#### [+] Union ( U )

<img src="./pic/union.png" width=400>

```
Two relations could have common tuples, but no nessarily
```
<img src="./pic/union2.png" width=400>

#### [+] Difference ( -- )
<img src="./pic/difference.png" width=400>

```
deduct the part belongs to R2 from R1, or reserve
```
<img src="./pic/difference2.png" width=400>

#### [+] Intersection ( &#x2229; )
<img src="./pic/intersection.png" width=400>

```
the common part both R1 and R2 have
```
<img src="./pic/intersection2.png" width=400>

#### [+] Cartesian-Product Operation 
##### &#x23f5; Notation: r x s
```
defined as:
r x s = {t q | t ∈ r and q ∈ s}, t, q are rows in r and s 

1) assume that attributes of r(R) and s(S) are disjoint (That is, R ∩ S = ∅)
2) if attributes of r(R) and s(S) are not disjoint, then renaming must be used
```
<img src="./pic/cartesianProductOperation.png" width=400>

##### &#x23f5; **&#x03ec;**<sub>A=C</sub>(r x s)
```
select rows where the value of A = C
```
<img src="./pic/cartesianProductOperation2.png" width=400>

#### [+] Join 
##### &#x23f5; Cartesina Product (could)= "join"
```
benefit: 
+ taking Cartesian prodcut of two relations give us all the possible tuples that are paired together

donwside:
- not efficient when huge relations with thousands of tuples that having large amount of attributes
```


##### &#x23fb; Mental Presentation (attribute level)
```
1) join operates at attribute(row) level, 
2) all attributes from two table will be collected together 
   as the attributes list for the newly combined table
3) if there are attributes with the same name, renaming is needed

-------------------------------------------------
| attribute 1 | attribute 2 | ... | attribute n |
-------------------------------------------------
.
.
.

```

##### &#x23f5; Theta Join 
```
• allows for arbitrary comparision relationship (such as >, < and =)
  => natural join with conditions

student                         Subject 
____________________            ___________________
| SID | Name | Std |            | Class | Subject |
|-----|------|-----|            |-------|---------|
| 101 | Alex |  10 |            |   10  |   Math  |
| 102 | Lucy |  11 |            |-------|---------|
--------------------            |   10  | English |
                                |-------|---------|
                                |   11  |  Music  |
                                |-------|---------|
                                |   11  |  Sport  |
                                -------------------
```
**theta(θ) join:** STUDENT ⋈ <sub>Student.Std = Subject.Class</sub> SUBJECT 
```
result: 

Std = Class, so all the values are equal, there are just different attribute name
------------------------------------------------
|  SID  |  Name  |  Std  |  Class  |  Subject  |
|-------|--------|-------|---------|-----------|
|  101  |  Alex  |   10  |    10   |    Math   |
|-------|--------|-------|---------|-----------|
|  101  |  Alex  |   10  |    10   |  English  |
|-------|--------|-------|---------|-----------|
|  102  |  Lucy  |   11  |    11   |   Music   |
|-------|--------|-------|---------|-----------|
|  102  |  Lucy  |   11  |    11   |  Sports   |
------------------------------------------------

```
###### &#x23fb; Another Example
<img src='./pic/thetaJoin.png' width=500>

##### &#x23f5; Equijoin 
```
above example actually could be regarded as an equijoin
```

##### &#x23f5; Natrual Join 
```
1) an equijoin on attributes(at least one) that have the same name in each relationship 
2) additionally, natrual join removes the duplicate columns 
   involved in the equality comparison so only 1 of each compared column remains


R = (a, B, C, D) 
S = (E, B, D)

• Result schema = (a, B, C, D, E)
• r ⋈ s is defined as:
```
**&#x03c0;**<sub>r.a, r.B, r.C, r.D, r.E</sub>(**&#x03ec;**<sub>r.B=s.B ∧ r.D=s.D</sub>(r x s))

<img src="./pic/natrualJoin.png" width=400>

```
---------------------------------------------------------------------------------------------
| 1) cross-product (cartesian product) of r and s                                           |
| 2) since both relations have attributes B and C, choose rows where r.B = s.B & r.D = s.D  |
|                                                                                           |
| 3) Must have at least one same attribute name in both tables(relations) for natural join  |
---------------------------------------------------------------------------------------------
```

### Examples for RA query
```
+ Natural Join could combine different attributes into one relations 
+ building connection between all attributes from one table and all attributes from the other table
```
##### &#x23f5; solution steps 
```
1) what will be in the result ? 
2) which table give us what from 1) ?
3) conditions ?
4) which table give us the conditions ?
```
#### 1) Sample Query
<img src="./pic/sampleQuery1.png" width=500>

```
1) sname 
2) saliors give sname 
3) bid = #103
4) boats and reserves (the connection we need to build [sname ~ bid])
```

#### 2) Sample Query
<img src="./pic/sampleQuery2.png" width=500>

```
1) sname 
2) saliors give sname 
3) color = red 
4) boats, reserves and sailor (connection we need to build is sname ~ color)
```
*Answer:* π<sub>sname</sub>((Ϭ<sub>color='red'</sub>Boats) ⋈ Reserves ⋈ Salior)

#### 3) Sample Query
<img src="./pic/samplyQuery3.png" width=500>

```
1) sname 
2) salior 
3) color = 'red' or 'green'
4) sailors, boats and reserves

same logic as query2, but but here introduce a new way of construct query 
```
**create temporary relation:** ⍴(Tempboats, (Ϭ<sub>color='red' ⋁ color='green'</sub>Boats)) <br>
**Final Answer:** π<sub>sname</sub>(Tempboats ⋈ Reserves ⋈ Sailors)

#### 4) Sample Query
<img src="./pic/sampleQuery4.png" width=500>

```
same logic, but using "and" operator
```

**saliors who reserve red boat:**   ⍴(Tempred, π<sub>sid</sub>(Ϭ<sub>color='red'</sub>Boats ⋈ Reserves)) <br>
**saliors who reserve green boat:** ⍴(Tempgreen, π<sub>sid</sub>(Ϭ<sub>color='green'</sub>Boats ⋈ Reserves)) <br>
**intersect them(because both red and green at the same time):** π<sub>sname</sub>((Tempred ⋂ Tempgreen) ⋈ Sailors)


#### 5) Sample Query
<img src="./pic/sampleQuery5.png" width=500>

```
in the query 4 logic: 
when asking who reserve red boat 
the sailor we found could not only have red boat reserved but other colors as well

<>: negation
```
**saliors who reserve red boat:** ⍴(Tempred, π<sub>sid</sub>(Ϭ<sub>color='red'</sub>Boats ⋈ Reserves)) <br>
**saliors who reserve other color boats but not red:** ⍴(Tempothers, π<sub>sid</sub>(Ϭ<sub>color=<>'red'</sub>Boats ⋈ Reserves)) <br>
**salior reserve red and other colors - who reserve other color except red: <br>**
π<sub>sname</sub>((Tempred - Tempother) ⋈ Sailors)

#### 6) Self Join (natural join)
<img src="./pic/selfJoin.png" width=550>

#### 7) Practice: find maximum


# SQL & schema definitions

### why SQL?
```
Find all bars that sell beers above $2.5 

sells 
----------------------------
|  bar  |  beer  |  price  |
|---------------------------
| Joe's |   Bud  |   2.50  |
|-------|--------|---------|
| Joe's | Miller |   2.75  |
|-------|--------|---------|
| Sue's |   Bud  |   2.50  |
|-------|--------|---------|
| Joe's |  Coors |   2.50  |
----------------------------

PROJECT bar (SELECT price > 2.5 Sells)

--------------------------------------------------------------------------------------------
reason to use SQL 
1) may be hard for ordinary programmers to write (especially when the query becomes complex)

2) better devise a query language that is more "English", more understandable

3) A SQL query can be translated into a RA expression
```

### Definition 

#### [+] SQL (Structured Query Language)
```
very high-level programming language, every SQL will be optimized before execution
```
#### [+] Data Definition Language (DDL)
```
+ define relational schemata 
+ create/alter/delete tables 
```
#### [+] Data Manipulation Language (DML)
```
+ Insert/delete/modify tuples in tables 
+ Query one or more tables
```
<img src="./pic/SQLtable.png" width=600>

```
1) Attributes must have an atomic type in standard SQL (not a list, set, etc)
                           ------

2) Atomic type 
    • Boolean 
    • Numbers:   INT, BIBINT, SMALLINT, FLOAT
    • Character: CHAR(20), VARCHAR(50)
    • Others:    MONEY, DATETIME

3) The number of attributes is the arity of the relation 
                                   -----
                                must be unique
```

#### [+] Table Schemas 
```
1) The schema of a table is the table name, its attributes, and their types 

--------------------------------------------------------------------------------
|   Product(Pname:string, Price:float, Category:string, Manufacturer:string)   |
--------------------------------------------------------------------------------

2) A key is an atrribute whose values are unique; we underline a key 

---------------------------------------------------------------------------------
|   Product(Pname:string, Price:float, Category:string, Manufacturer:string)    |
|           -----                                       ------------            |
|                                                                               |
---------------------------------------------------------------------------------
```


#### [+] Key Constraints 
```
A key is a minimal subset of attributes that acts as a unique identifier for tuples in a relation

1) lots of attributes 
   minimal subset of attributes mean that key should have at least one attribute

2) unique identifier for tuples
```

##### &#x23f5; NULL & NOT NULL
```
to say "don't know the value" we use NULL

---------------------
| sid | name | gpa  |
|-----|------|------|
| 123 | Bob  | 3.9  |
|-----|------|------|
| 143 | Jim  | NULL |       say, Jim just enrorlled in his first class 
---------------------

In SQL, we may constrain a column to be NOT NULL, for example "name" in this table can't be unknown
```

##### &#x23f5; General Constraints 
```
In theory, we can specify as many arbitrary constraints as possible 

but we don't do that, because Performance!
------------------------------------------
whenever we do something ugly (or avoid doing something convenient) it's for the sake of performance
```
#### [+] Summary 
```
Schema and Constraints are useful for optimization
```

# Single-table queries 

#### [+] renaming 
```
If you want the result to have different attribute names, use "AS <new name>" to rename

table:
Beers(name, manf)
-----------------
SELECT name AS beer, manf 
FROM Beers 
WHERE manf = 'Anheuser-Busch'
```

#### [+] NULL 
```
1) Tuples in SQL relations can have NULL as a value for one or more components 

    + Missing Value: we know Joe's Bar has some address, but we don't know what it is 
    + Inapplicable:  the value of attribute spouse for an unmarried person

2) SQL will evaluate to TRUE only if it knows for *sure*
3) SQL will return only cases for which it evaluates to TRUE 

--------------------------------------------------------------------------------------------
ex.
(price < 2.00) OR (price >= 2.00)
(price >= 2.00)

intuitively, price could be less than 2.00, or greater or equal to 2.00 -> doesn't know for sure
```

##### &#x23f5; Three-Valued Logic 
```
The logic of conditions in SQL is a 3-valued logic: 
1) TURE
2) FALSE 
3) UNKNOWN

• when any value is compared with NULL, the truth value is UNKNOWN 
  but query only produces a tuple in the answer if its truth value for the WHERE clause is TRUE
```

##### &#x23f5; Three-valued logic Example 
```
1) TURE = 1 
2) FALSE = 2 
3) Unknown = 1/2 
-----------------
I)   AND = MIN 
II)  OR = MAX 
III) NOT(x) = 1-x 
-----------------

(age > 20) AND ((age < 10) OR NOT (price < 5))
                      |
                      V 
TRUE AND (FALSE OR NOT(Unknown)) = MIN(1, MAX(0, (1-1/2))) = MIN(1, MAX(0, 1/2)) = MIN(1, 1/2) = 1/2 = unknown


ex). From the Following Sells relation:

        ----------------------------
        |    bar    | beer | price |
        |-----------|------|-------|
        | Joe's bar | Bud  | NULL  |
        ----------------------------

        SELECT bar
        FROM Sells 
        WHERE price < 2.00 OR price >= 2.00 
              ------------    -------------
                unknown          unknown
             <----------------------------->
                         unknown
```

##### &#x23f5; Testing for Null 
```
SELECT * FROM Person 
WHERE age < 25 OR age >= 25 OR age IS NULL 
      ---------------------    -----------
   won't include null value     Null value is included
```

#### [+] Constraints
```
1) NOT NULL 
2) DEFAULT 
3) UNIQUE 
4) CHECK 

constrain enforcement
---------------------------------------------
CREATE TABLE COMPANY(
    ID      INT  primary key NOT NULL,
    NAME    TEXT             NOT NULL,
    AGE     INT              NOT NULL UNIQUE,
    ADDRESS CHAR(50),
    SALARY  REAL             DEFAULT 50000.00
);
```

# Multi-table queries 
#### [+] Foreign key constraints 
<img src="./pic/foreignKey.png" width=750>

##### &#x23f5; Foreign Keys and update operations 
<img src="./pic/foreignKeyOperation.png" width=500>

<img src="./pic/foreignKeyExample.png" width=500>

#### [+] Joins

##### &#x23f5; Example 1 
<img src="./pic/SQLJoin.png" width=600>

```
alternative way to write query 

(method 1)                                  (method 2)
SELECT PName, Price                         SELECT PName, Price 
FROM   Product, Company                     FROM   Product 
WHERE  Manufacturer = CName                 JOIN   Company On Manufacturer = 'CName' (foreign key)
AND    Country = 'Japan'                    AND    Country = 'Japan'
AND    Price <= 200                         WHERE  Price <= 200

=================
I prefer method 1
```

##### &#x23f5; Example 2
<img src="./pic/SQLJoin2.png" width=600>

#### [+] Tuple Variable Ambiguity in Multi-Table 
<img src="./pic/tupleVariableAmbiguity.png" width=600>

```
we cannot do this: 
-----------------------------
SELECT DISTINCT name, address 
FROM Person, Company 
WHERE worksfor = name 

which name and address are we refering?
```
#### [+] SQL semantics 
<img src="./pic/SQLsemantics.png" width=600>
<img src="./pic/SQLsemanticsJoin.png" width=600>

```
semantics ≠ execution order, DBMS executes command after optimization
```
##### &#x23f5; Unintuitive Query for understanding why operating with ∅ will result in ∅ 
```

```

#### [+] Multiset Operations 
##### &#x23f5; Multisets 
<img src="./pic/multisets1.png" width=600>
<img src="./pic/multisets2.png" width=600>
<img src="./pic/multisets3.png" width=600>

##### &#x23f5; Multisets Operations
###### &#x23fb; Intersect
```
SELECT R.A FROM R, S 
WHERE R.A = S.A 
INTERSECT 
SELECT R.A FROM R, T 
WHERE R.A = T.A
```
<img src="./pic/intersect.png" width=250>

###### &#x23fb; Union
```
SELECT R.A FROM R, S 
WHERE R.A = S.A 
UNION 
SELECT R.A FROM R, T 
FROM R, T
WHERE R.A = T.A

by default, SQL operator uses set semantics, so there aren't duplicate after single operation
```
<img src="./pic/mutlisetUnion.png" width=250>

###### &#x23fb; Union All
```
SELECT R.A FROM R, S 
WHERE R.A = S.A 
UNION ALL
SELECT R.A FROM R, T 
FROM R, T
WHERE R.A = T.A
```
<img src="./pic/unionAll.png" width=350>

###### &#x23fb; Except
```
EXCEPT (replace where above operator is)
```
<img src="./pic/except.png" width=350>

##### &#x23f5; Issues with Intersect
<img src="./pic/intersectIssue.png" width=600>

```
As the green background text indicates:
all companies with factories in the US will be return, so as those with factory in China 
but at the same time, companies that have company exclusively located in one place will be selected as well 

intuitively, we want to use intersect to meet the criteria, but in fact fail in this case
|
V 
introduce nexted queries for solving issues that require intersect operation logic
```
#### [+] Nested Queries
<img src="./pic/nestedQuery.png" width=600>

```
refer to those example in the slides
```

# Aggregation & Group By
#### [+] Aggregation Operator 
```
1) SUM 
2) COUNT 
3) MIN 
4) MAX 
5) AVG
```
##### &#x23f5; COUNT

##### &#x23f5; GROUP BY 

##### &#x23f5; HAVING
```
1) HAVING clauses operate on aggregate condition (column level) 

2) WHERE clauses operate on individual tuples (row level)
```

##### &#x23f5; Quantifiers 
```
DISTINCT
```

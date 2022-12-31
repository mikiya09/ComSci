
from dotenv import load_dotenv, find_dotenv
import os
import pprint 
from pymongo import MongoClient 
from bson.objectid import ObjectId
# create a .env file within the same directory
load_dotenv(find_dotenv())


# ==================================================== connect ======================================================

# connection setup
password = os.environ.get("MONGODB_PWD")
# remember to replace the password field
connection_string = f"mongodb+srv://mikiya:{password}@test01.ydhguxj.mongodb.net/?retryWrites=true&w=majority"

client = MongoClient(connection_string)

# collect all the database inside 
dbs = client.list_database_names()
# specific database with their name 
test_db = client.test
# check collections in a database 
collections = test_db.list_collection_names()
# print them
print(dbs)
print(collections)


# ==================================================== insert ======================================================
def insert_doc():
    # dot operation could access document in database directly
    collection = test_db.person
    person_document = {
            "first_name": "Xirong",
            "last_name": "Cao"
            }
    # each document inserted into the collection will generated ID automatically
    # that is the unique identifier, like the primary key in Relationsl database
    inserted_id = collection.insert_one(person_document).inserted_id 
    print(inserted_id)


# ==================================================== create collections & insert multiple ======================================================
# use production command 
production = client.production 
# just a override on the variable, the point is you use client.production command
people_collection = production.people_collection
# can't create empty collections, you have to insert some document for it to exist 
def create_documents():
    first_names = ["Itachi", "Kisame", "Jotaro", "Dio", "Bruno", "Joseph"]
    last_names = ["Uchiha", "Hoshigaki", "Kujo", "Brando", "Buccellati", "Joestar"]
    ages = [21, 33, 18, 100, 20, 68]

    # create a list for append 
    docs = [] 

    # loop through the document using zip package 
    for first_name, last_name, age in zip(first_names, last_names, ages):
        doc = {"first_name": first_name, "last_name": last_name, "age": age}
        docs.append(doc)
        # people_collection.insert_one(doc) ==> we don't wannna insert them one by one 

    people_collection.insert_many(docs)

# create_documents()


# ==================================================== read data ======================================================
# nicer print format 
printer = pprint.PrettyPrinter()
# find all people 
def find_all_people():
    people = people_collection.find()
    # you can also store them ==> list(people)

    for person in people:
        printer.pprint(person)

# there's also a cursor object in pymongo, I think you can make use of it 
# find_all_people()

# find specific person without knowing the _id
def find_target():
    target = people_collection.find_one({"first_name": "Itachi"})
    printer.pprint(target)
    # if there are multiple matches, only the first one will be returned

# count documents inside a collection 
def count_all_people():
    count = people_collection.count_documents(filter={})
    print("Number of people", count)

# get person by id 
def get_person_by_id(person_id):
    
    # normal string type of id need to be converted into bson type in mongoDB: ObjectId()
    _id = ObjectId(person_id)                    # add underscore so don't messed up with python built-in id
    person = people_collection.find_one({"_id": _id})
    printer.pprint(person)

# get_person_by_id("63b0a0521bdc4c0f55358575")
print()

# get data in range using pymongo query operator
def get_age_range(min_age, max_age):
    """
    SELECT * FROM people WHERE age >= min_age AND age <= max_age
    """
    # speical query operator format in pymongo
    query = {"$and": [
        {"age": {"$gte": min_age}},     # gte: greater or equal
        {"age": {"$lte": max_age}}      # lte: less or equal 
    ]}

    people = people_collection.find(query).sort("age")
    for person in people:
        printer.pprint(person)

get_age_range(20, 30)

# only select key field we want 
def project_columns():
    # given it an 1 means true, 0 means false
    columns = {"_id": 0, "first_name": 1, "last_name": 1}
    people = people_collection.find({}, columns)
    for person in people:
        printer.pprint(person)

print()
project_columns()

# ==================================================== update ======================================================
# update by id 
def update_person_by_id(person_id):

    _id = ObjectId(person_id)

    # do it with query operator 
    all_updates = {
            "$set": {"test": True},                                     # set 
            "$inc": {"age": 1},                                         # increment int value 
            "$rename": {"first_name": "first", "last_name": "last"}     # rename key names
            }
    people_collection.update_one({"_id": _id}, all_updates)

    # to see the changes, comment out above code 
    # passing an empty string for removing test, is because python process it as dictionary, can't leave it empty
    people_collection.update_one({"_id": _id}, 
                                 {"$unset": {"test": ""},
                                  "$rename": {"first": "first_name", "last": "last_name"}})

    return 


# replace: we want to update some value, but keep other field unchange, specially for _id 
def replace_one(person_id):
    _id = ObjectId(person_id)

    new_doc = {
            "first_name": "ITACHI",
            "last_name": "UCHIHA",
            "age": 100
            }
    # use replace command 
    people_collection.replace_one({"_id": _id}, new_doc)
    return

# replace_one("63b0a0521bdc4c0f55358575")


# ==================================================== delete ======================================================
def delete_doc(person_id):
    _id = ObjectedId(person_id)
    # delete one 
    people_collection.delete_one({"_id": _id})
    # delete all
    # people_collection.delete_many({})

    return

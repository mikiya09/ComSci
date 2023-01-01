
from dotenv import load_dotenv, find_dotenv
import os
import pprint
from pymongo import MongoClient
from bson.objectid import ObjectId
from datetime import datetime as dt
# create a .env file within the same directory
load_dotenv(find_dotenv())


# ==================================================== connect ======================================================

# connection setup
password = os.environ.get("MONGODB_PWD")
# remember to replace the password field
connection_string = f"mongodb+srv://mikiya:{password}@test01.ydhguxj.mongodb.net/?retryWrites=true&w=majority&authSource=admin"

client = MongoClient(connection_string)

# collect all the database inside
dbs = client.list_database_names()
production = client.production


# ======================================= Schema Validation ========================================
# create book collection
def create_book_collection():
    book_validator = {
        "$jsonSchema": {
            "bsonType": "object",
            "required": ["title", "authors", "publish_date", "type", "copies"],
            "properties": {
                "title": {
                    "bsonType": "string",
                    "description": "must be a string and is required"
                },
                "authors": {
                    "bsonType": "array",
                    "items": {
                        "bsonType": "objectId",
                        "description": "must be an objectid and is required"
                    }
                },
                "publish_data": {
                    "bsonType": "date",
                    "description": "must be a date and is required"
                },
                "type": {
                    "enum": ["Fiction", "Non-Fiction"],
                    "description": "can only be one of the enum values and is required"
                },
                "copies": {
                    "bsonType": "int",
                    "minimum": 0,
                    "description": "must be an integer greater than 0 and is required"
                },
            }
        }
    }
    try: 
        production.create_collection("book")
    except Exception as e:
        print(e)

    production.command("collMod", "book", validator=book_validator)
    return

# create author collection
def create_author_collection():
    author_validator = {
       "&jsonSchema": {
            "bsonType": "object",
            "required": ["first_name", "last_name", "date_of_birth"],
            "properties": {
                "first_name": {
                    "bsonType": "string",
                    "description": "must be a string and is reuqired"
                },
                "last_name": {
                    "bsonType": "string",
                    "description": "must be a string and is required"
                },
                "date_of_birth": {
                    "bsonType": "date",
                    "description": "must be a date and is required"
                },
            }
        }
    }
    try: 
        production.create_collection("author")
    except Exception as e:
        print(e)
    production.command("collMod", "author", validator=author_validator)
    return

# create_author_collection()



# create data in seperate collection instead of embedded 
def create_date():
    # authors collection
    authors = [
        {
            "first_name": "Xirong",
            "last_name": "Cao",
            "date_of_birth": dt(1995, 11, 13)
        },
        {
            "first_name": "F. Scott",
            "last_name": "Fitzgerald",
            "date_of_birth": dt(1896, 9, 24)
        },
        {
            "first_name": "O. Henry",
            "last_name": "not provided",
            "date_of_birth": dt(1862, 9, 11)
        },
        {
            "first_name": "big brother",
            "last_name": "not provided",
            "date_of_birth": dt(2000, 1, 1)
        },
    ]
    # production.author: for insert value
    author_collection = production.author 
    # grab ids
    try: 
        authors = author_collection.insert_many(authors).inserted_ids
    except:
        print("here")


    # book collections
    books = [
        {
            "title": "the world!",
            "authors": [authors[0]],    # because we have grab the id for all the authors, so we can access them using index
            "publish_date": dt.today(),
            "type": "Fiction",
            "copies": 5
        },
        {
            "title": "How to speak like me",
            "authors": [authors[3]],
            "publish_date": dt.today(),
            "type": "Fiction",
            "copies": 5
        },
        {
            "title": "How to master your stand",
            "authors": [authors[3]],    
            "publish_date": dt.today(),
            "type": "Fiction",
            "copies": 5
        },
        {
            "title": "After Twenty Years",
            "authors": [authors[2]],
            "publish_date": dt(1906, 1, 1),
            "type": "Fiction",
            "copies": 5
        },
        {
            "title": "The Great Gatsby",
            "authors": [authors[1]],
            "publish_date": dt(2014, 5,23),
            "type": "Fiction",
            "copies": 5
        },
    ]
    # insert values
    book_collection = production.book 
    book_collection.insert_many(books)

# create_date()



# ======================================= pymongo arrow ========================================
import pyarrow 
from pymongoarrow.api import Schema 
from pymongoarrow.monkey import patch_all
import pymongoarrow as pma 

# patch all the apis that work with mongodb's collections, just make sure you run this command 
patch_all()

# specify attributes that you want to get 
author = Schema({"_id": ObjectId, "first_name": pyarrow.string(),
                 "last_name": pyarrow.string(), "date_of_birth": dt})

# pandas dataframe 
df = production.author.find_pandas_all({}, schema=author)   # id is in binary form

# arrow table is what all attributes collected into a list 
arrow_table = production.author.find_arrow_all({}, schema=author)

# array 
ndarrays = production.author.find_numpy_all({}, schema=author)

print(df)

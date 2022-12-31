
from dotenv import load_dotenv, find_dotenv
import os
import pprint 
from pymongo import MongoClient 
# create a .env file within the same directory
load_dotenv(find_dotenv())


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

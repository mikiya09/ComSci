
import sqlite3
from prettytable import from_db_cursor 
import pandas as pd

# =================== connection ===================
# connection object 
conn = sqlite3.connect('test.db')

# cursor object 
cursor = conn.cursor() 

# drop table if already exist 
cursor.execute("drop table if exists graph")

# creating table 
table = """ 
create table graph (
        source int,
        destination int
        ); 
"""




# execution 
cursor.execute(table)
print("Table is Ready")


# =================== basic queries ===================
# insert tuples, you can still execute without cursor
# cursor is just an obect that perform specific task as you defined
# for multiple insert, you first need to have some data inside 
conn.execute("insert into graph VALUES (5, 11)")

# path 
paths = [
        (11, 2),
        (11, 9),
        (11, 10),
        (7, 11),
        (7, 8),
        (8, 9),
        (3, 8),
        (3, 10),
]
# conn.execute("insert into graph VALUES (11, 2)")
# conn.execute("insert into graph VALUES (11, 9)")
# conn.execute("insert into graph VALUES (11, 10)")
# conn.execute("insert into graph VALUES (7, 11)")
# conn.execute("insert into graph VALUES (7, 8)")
# conn.execute("insert into graph VALUES (8, 9)")
# conn.execute("insert into graph VALUES (3, 8)")
# conn.execute("insert into graph VALUES (3, 10)")

# insert many at once 
conn.executemany("insert into graph VALUES (?, ?)", paths)
print("All data had been inserted")

# print all rows in the table in a ugly way
cursor.execute("select * from graph")
print(cursor.fetchall())

# print(pd.read_sql_query("select * from graph", conn)) -- pd way

# pretty table: ASCII tables
cursor.execute("select * from graph")
my_graph = from_db_cursor(cursor)
print(my_graph)

# for loop way
# cursor = conn.execute("select * from graph")
#
# # display all data from graph table
# for row in cursor:
#     print(row)


# =========================== Alter Table ===========================
# alter table with new columns 
weight_column = "alter table graph add column weight int"
cursor.execute(weight_column)

# update table
cursor.execute("update graph set weight = ABS(random()) % (10) + 1")

# check if new column is added
cursor.execute("select * from graph")
print(from_db_cursor(cursor))

# close connection 
conn.close()

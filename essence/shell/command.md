
# Shell Command

### Permissions 

#### chmod (change mode)
```
# long listing 
>> ls -l

 -   ---     ---     ---
d/-  rwx     rwx     rwx 
     user    group   other
```
##### &#x21e2; read, write, execute and - 
```
read(r):    read content 
write(w):   modify content 
execute(x): run files that are programs 
-:          if "rwx" is replaced by a "-", then that permission has been revoked
```

##### &#x21e2; user, group and others
```
user(u):   apply to only the owner of the file 
group(g):  the group that has been assigned to the file or directory 
others(o): all other users on the system that are not any of two above
```

#### &#x2314; examples 
```
# make this file that others user can run 
>> chmod o+x file.xxx

# give permission to run scripting file 
>> chmod +x gitPush 

# add (r) and (w) permission to both (u) and (g)
# revoke execute(x) permission from others(o) for file abc.mp4
>> chmod ug+rw,o-x abc.mp4 

# assign (r) and (x) permission to both (u) and (g) and add (r) permission to others for the file abc.c
>> chmod ug=rx,o+r abc.c
```

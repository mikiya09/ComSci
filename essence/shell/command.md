
# Shell Command

### &#x2314; Execution time
##### &#x21e2; time 
```
1) time python xxx.py       # check the execution time for a running program 
2) time ls                  # check the execution time for a command(shell)
```

### &#x2314; Permissions 

##### &#x21e2; chmod (change mode)
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

##### &#x21e2; examples 
```shell
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

### &#x2314; With Remote Server
##### &#x21e2; connect 
```shell
# need to change .pem mode so that only you can modify it (which is require step)
>> chmod 600 /path/to/.pem
# with .pem private key 
>> ssh -i access.pem username@ip-address
```

##### &#x21e2; [Copy](https://medium.com/srcecde/copy-file-directory-to-from-ec2-using-scp-secure-copy-685c46636399)
```shell
-------------------------------------------------------------------------------------------
# From local to remote 
# 1) syntax: scp [local file] username@ip-address:[remote directory]
# 2) the following exmaple use private key(.pem). Remove -i ai.pem if password is used 
# 3) scp -r: meaning copy file recursively from sub-directories
>> scp -i access.pem -r ~/wormhole/toKnow/dataset/ ubuntu@0.0.0.0:/home/ubuntu/llm/

# copy file from local to remote 
# remove -r: meaning just copy one file 
>> scp -i access.pem ~/wormhole/toKnow/data.csv ubuntu@0.0.0.0:/home/ubuntu/llm/newName

-------------------------------------------------------------------------------------------
# From remote to local is the reverse order 
>> scp -i access.pem -r ubuntu@0.0.0.0:/home/ubuntu/source_dir ~/Documents/directory1
```

### &#x2314; Intermediate Host


##### &#x21e2; Check IP
```
# check if ip-address exist in remote
>> nslookup 
```

##### &#x21e2; Projected Server
```
# protected server in remote
1) won't be able to check ip-address if the destination host is protected from the outside world 
2) in this case, you need a jump host, port is usually 22
```

##### &#x21e2; Jump Host: [FileZilla](https://www.unixcloudfusion.in/2016/01/using-filezilla-to-connect-ec2-with.html)
```
# tunnel way 
1) reserve a pane for opening a tunnel on your local host, which connect to the jump host (Intermediate one). 
>> ssh -D 8001 username@xxx.xxx.xxx

2) set up Generic Proxy in FileZilla
Settings > Generic Proxy > Socks 5: 
=====================
Proxy host: 127.0.0.1 
Proxy Port: 8001 
=====================
> Save, nothing more

3) connect through FileZilla UI: 
======================================
Host: destination-host
Username: destination-username
Password: destination-password 
Port: leave it empty
======================================
> Quickconnect 
```
##### &#x21e2; Jump Host (scp)
```
# from local to remote 
>> scp -J username@jumphost:22 /path/to/localfile user@destination:/home/user/directory

# from remote to local: I think it's the same idea?
1) open tunnel 
2) directly scp through the tunnel from local host?
```

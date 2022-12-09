
# What to do
```
[1] initialize repo 
[2] make changes 
[3] add changes to stage 
[4] commit changes 
[5] push/pull
[6] manage repo
[7] ignore some file
```

### [1] Intialize/Create local repo
```
>> cd "any_directory"               // which directory to use .git
>> git init                         // create .git files 
>> git status                       // check branch
```
### [2] Connect Local Repository with remote one (github)
##### &#x25cb; username and email 
```
1) username and useremail are used for tracking who are making changes to repo locally
2) could be any string, but better use the same as github one

>> git config --global user.name "JoJo"
>> git config --global user.email "spacelion121319@gmail.com"
>> git config -l                                                 // check username and email
```
##### &#x25cb; access token for login from terminal 
```
1) www.github.com --> settings --> Developers settings --> Personal Access Tokens
2) name your token || delete || expire || regenerate new one
3) generally, check mark repo option is enough
4) whenever you pull or push from github, if ask username and token: "JoJo" and that token
```

##### &#x25cb; set/cancel one-time pass (optional)
```
>> git config --global credential.helper cache          // set 
>> git config --global --unset credential.helper        // cancel
```
##### &#x25cb; setting up remote repo 
```
# create new repo on github 
# go to github page --> click "+" --> New Repository --> Name it --> Public/Private 

# set branch, could be any name instead of main
>> cd "xxx"
>> git branch -M main

# add from local
>> git remote add origin https://github.com/user_name/repo_name.git
```

##### &#x25cb; change remote repo -> refer to [*github docs*](https://docs.github.com/en/get-started/getting-started-with-git/managing-remote-repositories)
```
# list current remote repo 
>> git remote -v 

# change 
>> git remote set-url origin https://github.com/user_name/repo_name.git
```

### [3] Add changes 
```
>> git add filename.xxx             // add single file 
>> git add .                        // add all files 
```

### [4] Commit 
```
>> git commit -m "commit message"   // describe what you had changed in this commit
>> git status                       // check status
```
##### &#x25cb; cancel commit 
```
# undo last changes 
>> git reset

# undo all commit
>> git reset --soft HEAD~
```

### [5] Push/Pull
```
>> git push -u origin main          // when you have multiple branch, you need to specify one to push 
>> git push                         // if you only have one main branch
>> git pull origin main
```
### [6] Branch
##### &#x25cb; checkout/switch
```
# check out
>> git checkout -b new_branch               // -b: create new branchs 
                                            // git checkout: leave current branch 
>> git checkout main                        // leave current branch go to main

# switch
>> checkout branch_name 
```
##### &#x25cb; merge
```
# merge 
>> git merge main                           // merge all stuff in my branch to main

```
##### &#x25cb; List Branch
```
# list
>> git branch -a                            // list all branch 
>> git branch -r                            // list remote? 
>> git branch                               // try, won't kill you
```
##### &#x25cb; Delete Branch
```
# delete branch 
>> git branch -d branch_name                // won't let you delete the branch you currently in
>> git push origin --delete branch_name 

```
##### &#x25cb; Diverge/Converge
```
# branches diverge/converge
# if you make changes directly through github(remote)
# and make different changes in local repo at the same time 
# will cause version conflict 
>> git pull origin main 
>> git status 
>> git merge origin/branch_name             // here branch_name = main
```
##### &#x25cb; Rename Branch(main)
```
# go to repo -> settings -> under Code and automation -> click Branches -> rename it

# for local consistent, rename local as well 
>> git branch -m older_name new_name 
>> git fetch origin 
>> git branch -u origin/new_name new_name 
>> git remote set-head origin -a                // act that link and remote and local for push/pull, i guess
```

### [7] Ignore Some file
[auto-generating .gitignore](https://www.toptal.com/developers/gitignore)
```
include this file in the local .git directory for eliminating items you don't want to push 

>> vim .gitignore 
>> {copy and paste}
```

##### &#x25cb; Current Directory 
```
if you have .git repo inside a git repo, the .gitignore inside parent directory won't have effect on children's

don't do ths if not necessary
```

##### &#x25cb; syntax 
```
no pdf -> *.pdf
```

### publish site
```
Go to repos --> settings --> Pages --> under source select branch --> save 
```
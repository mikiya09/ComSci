
# What to do
```
[1] initialize repo 
[2] make changes 
[3] add changes to stage 
[4] commit changes 
[5] push/pull
[6] manage repo
```

### [1] Intialize/Create local repo
```
>> cd "any_directory"               // which directory to use .git
>> git init                         // create .git files 
>> git status                       // check branch
```
### [2] Connect Local Repository with remote one (github)
#### • username and email 
**username** and **useremail** are used for tracking who are making changes to repo locally
```
could be any string, but better use the same as github one

>> git config --global user.name "JoJo"
>> git config --global user.email "spacelion121319@gmail.com"
>> git config -l                                                 // check username and email
```
#### • access token for login from terminal 
```
1) www.github.com --> settings --> Developers settings --> Personal Access Tokens
2) name your token || delete || expire || regenerate new one
3) generally, check mark repo option is enough
4) whenever you pull or push from github, if ask username and token: "JoJo" and that token
```

#### • set/cancel one-time pass (optional)
```
>> git config --global credential.helper cache          // set 
>> git config --global --unset credential.helper        // cancel
```
#### • setting up remote repo 
```
# create new repo on github 
# go to github page --> click "+" --> New Repository --> Name it --> Public/Private 

# set branch, could be any name instead of main
>> cd "xxx"
>> git branch -M main

# add from local
>> git remote add origin https://github.com/user_name/repo_name.git
```

#### • change remote repo 
[github docs](https://docs.github.com/en/get-started/getting-started-with-git/managing-remote-repositories)
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
#### • cancel commit 
```
# undo last commit
>> git reset --soft HEAD~

# undo all changes 
>> git reset
```

### [5] Push/Pull
```
>> git push -u origin main 
>> git pull origin main
```
### [6] Manage Repo 
#### • Branch 
```
# check out
>> git checkout -b new_branch           // -b: create new branchs 
                                        // git checkout: leave current branch 
>> git checkout main                    // leave current branch go to main

# merge 
>> git merge main                       // merge all stuff in my branch to main

# list
>> git branch -a                        // list all branch 
>> git branch -r                        // list remote? 
>> git branch                           // try, won't kill you

# switch branchs 
>> checkout branch_name 

# delete branch 
>> git branch -d branch_name            // won't let you delete the branch you currently in
>> git push origin --delete branch_name 

# branches diverge/converge
# if you make changes directly through github(remote)
# and make different changes in local repo at the same time 
# will cause version conflict 
>> git pull origin main 
>> git status 
>> git merge origin/branch_name         // here branch_name = main
```

### .gitignore
[auto-generating .gitignore](https://www.toptal.com/developers/gitignore)
```
include this file in the local .git directory for eliminating items you don't want to push 

>> vim .gitignore 
>> {copy and paste}
```

### publish site
```
Go to repos --> settings --> Pages --> under source select branch --> save 
```

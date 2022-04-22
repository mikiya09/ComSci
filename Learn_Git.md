
# Starting Using Git

# Logic
    [#] initialize repo --> make changes --> add changes to stage --> commit changes --> push

# create a git local repo 
    >> cd "any_folder"
    >> git init
    >> git status

# connect local repo with remote repo (github)
    [#] user-name and user-email initialize
    [#] username and email could be any valid one, the reason for doing this is to keep track of who are making changes to repo
    >> git config --global user.name "JoJo"
    >> git config --global user.email "spacelion121319@gmail.com"
    >> git config -l

# github require access token for login from terminal
    [#] www.github.com --> settings--> Developer settings --> Personal access tokens
    [#] name your token & delete & expire & regenerate new one
    [#] generally, check repo is enough
    [#] whenever you pull or push file to github, and ask for username and token, you know what to use

# set one-time pass
    >> git config --global credential.helper cache

# cancel or reset one-time pass
    >> git config --global --unset credential.helper

# basic command
    [1] stage area
    >> git add filename.xxx                   (add single file)
    >> git add .                              (add all file to local repo)
    [2] commit
    >> git commit -m "commit message"         (describe what you had changed in this commit)
    >> git status                             (check current state)
    [3] branch
    >> git checkout -b new_branch             (-b: make a new branch, git checkout: leave current branch)
    >> git checkout master/main               (branch name followed checkout)
    >> git merge master                       (merge all stuff in my branch to master)

# setting up remote repo
    [#] --> github.com --> "+" --> New Repository --> Name it --> Public/Private --> nothing more needed to add
    >> git remote add origin https://github.com/user_name/repo_name.git
    >> git checkout master/main


# Changing remote repo
    [list current remote repo & also for checking]
    >> git remote -v

    [change]
    >> git remote set-url origin https://github.com/userName/repoName.git

    [reference]
    >> https://docs.github.com/en/get-started/getting-started-with-git/managing-remote-repositories

# push & pull
    [!]: when you create a new repo through github, pay attention to the name you adopt ("master" -> "main") 
    >> git push -u origin master/main
    >> git pull origin master/main

# Branch
    [#] list all branch (remote and local)
    >> git branch -a
    >> git branch -r
    >> git branch 

    [#] create new branch
    >> git checkout -b branch_name
    [#] switch branch
    >> checkout branch_name
    [#] delete branch (local and remote)
    [!] git will not let you delete the branch you are currently on
    >> git branch -d branch_name
    >> git push origin --delete branch_name

# push another branch
    >> checkout other_branch
    >> git push origin other_branch
    [!] check on github website 

# branchs diverge/converge
    [!] if you make changes directly through github(remote), instead of locally
        - you are unable to push next time until you pull down the changes
        - but when you do that, it will likely cause two branch diverge
        - manually solve that by
    >> git pull origin master/main
    >> git status
    >> git merge origin/branch_name

# .gitignore
    [#] there are files come with systems and you don't want to upload them to public repo
    [#] https://www.toptal.com/developers/gitignore
    [#] type in any OS you are using, and auto-generating .gitignore file for you
    >> cd "you folder"
    >> vim .gitignore
    [#] [copy & paste]
    [#] done!

# publish site
    [#] go repo --> settings --> Pages --> under source select branch --> save 

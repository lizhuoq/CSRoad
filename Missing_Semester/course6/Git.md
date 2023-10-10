# Git  
1. git clone <url>  
2. 建立feature branch: git checkout -b my-feature  
3. 查看改变: git diff  
4. 添加修改文件到暂存区: git add <changed_file>  
5. 告知local git: git commit  
6. 告知github: git push <远程主机名> <本地分支名>:<远程分支名> git push origin my-feature    
## main branch 有更新  
7. git checkout main  
8. git pull <远程主机名> <远程分支名>:<本地分支名> git pull origin master  
9. git checkout my-feature  
10. git rebase main  
11. git push -f origin my-feature  
12. pull request: 要求项目的主人将我的分支pull到项目里  
13. squash and merge: 将要pull的改变合并为一个改变，然后更新  
## 更新后  
14. 删除远端branch  
15. git checkout main  
16. 删除my-feature branch: git branch -D my-feature  
17. 将最新的更新拉到local: git pull origin master  


# ft_ls: a 42 project

The goal of this project was to copy the functionality of the command line tool ls. That includes all of the weird functionality like sticky bits and the /dev folder. The options included in this implementation are -l, -R, -r, -a, and -t. (Refer to the man for more information.) Columns are not supported, and we were not require to handle ACL. 

Authorized functions: 
- write
- opendir
- readdir
- closedir
- stat
- lstat
- getpwuid
- getgrgid
- listxattr
- getxattr
- time
- ctime
- readlink
- malloc
- free
- perror
- strerror
- exit

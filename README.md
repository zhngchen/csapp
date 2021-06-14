# csapp lab的记录

## datalab
环境wsl2
注意：要把makefile中的CFLAGS,32改为64

检查： ./dlc bits.c
编译运行：make clean; make btest; ./btest
         测试某个函数 ./btest f [args];


a == b   !(a ^ b)
a >= 0  !(a & 0x01 << 31), !(a >> 31)
取出a的后四位  a & 0x0F
!!x 的使用
要注意运算的是bool还是int

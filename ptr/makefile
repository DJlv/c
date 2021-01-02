  mx =calc
  
  cc = gcc
  hx = $(shell find ./name "*.h")             #.h文件
  cx = $(shell find ./ -name "*.c")           #.c文件
  ox = $(cx:%.c=%.o)          #.o文件
  
  
  $(mx): $(ox)
     $(cc) -o $(mx) $(ox)

 %.o:%.c $(hx)
      $(cc) -c $< -o $@

 cleanm:
    rm -rf $(ox)
 clean:
    rm -rf $(ox) $(mx)

# 静态链接编译过程
# STATIC_LIB_NAME = mymath
# TARGET = main

# $(TARGET):lib$(STATIC_LIB_NAME).a
# 	g++ -o $(TARGET) main.cc -L. -l$(STATIC_LIB_NAME)

# SOURCES = $(wildcard [!m]*.cc)
# OBJS = $(patsubst %.cc,%.o,$(SOURCES))

# lib$(STATIC_LIB_NAME).a:$(OBJS)
# 	@# 由.o文件创建静态库.a文件
# 	ar cr lib$(STATIC_LIB_NAME).a $(OBJS) 

# %.o:%.cc
# 	g++ -c $< -o $@

# clean:
# 	rm -rf *.o *.a

# 动态链接编译过程
DYNAMIC_LIB_NAME = mymath
TARGET = main

$(TARGET):lib$(DYNAMIC_LIB_NAME).so
	g++ -o $(TARGET) main.cc -L. -l$(DYNAMIC_LIB_NAME); \
	cp lib$(DYNAMIC_LIB_NAME).so /usr/lib/; \
	export LD_LIBRARY_PATH=/usr/lib:$LD_LIBRARY_PATH; \
	ldconfig

SOURCES = $(wildcard [!m]*.cc)
OBJS = $(patsubst %.cc,%.o,$(SOURCES))

lib$(DYNAMIC_LIB_NAME).so:$(OBJS)
	@# 由.o文件创建动态库.so文件
	g++ -shared -o lib$(DYNAMIC_LIB_NAME).so $(OBJS) 

%.o:%.cc
	g++ -fPIC -c $< -o $@

clean:
	rm -rf *.o *.so

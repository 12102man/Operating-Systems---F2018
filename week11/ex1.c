 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>

int main() {
	
	int fp = open("./file1.txt", O_RDWR);
	const char* string = "This is a nice day";
	size_t stringsize = strlen(string) + 1;

  	lseek(fp, stringsize-1, SEEK_SET);
  	ftruncate(fp, stringsize);
 	char *map = mmap(0, stringsize, PROT_READ|PROT_WRITE, MAP_SHARED, fp, 0);
  	memcpy(map, string, stringsize-1);
  	msync(map, stringsize, MS_SYNC);
  	munmap(map, stringsize);
  	close(fp);
  	return 0;


}
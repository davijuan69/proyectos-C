int my_strlen(const char *s){
register const char *p = s;
while(*p) //*p!=‘\0'
p++;
return p-s;
}

void my_strcpy(char *d, const char *f){
while(*d++ = *f++);
}

void my_strcat(char *d, const char *f){
my_strcpy(d+my_strlen(d),f);
}

char *my_strdump(const char *f){
char *d;
d=(char *)malloc(my_strlen(f)+1);
my_strcpy(d,f);
return d;
}

int my_substr(const char *s1, const char *s2){
int i,v;
const char *p1,*p2;
v=my_strlen(s2)-my_strlen(s1);
for(i=0;i<=v;i++)
for(p1=s1,p2=s2+i;*p1++==*p2++;)
if(*p1=='\0') return i;

return -1;
}
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    FILE *fp = fopen(argv[1], "w");
    
    int len = strlen(argv[1]);
    char NAME[len];
    int i = 0;
    while (argv[1][i] != '.') {
        NAME[i] = argv[1][i];
        i++;
    }
    fprintf(fp, "#include <stdio.h>\n\n//Code Provided Automatically by Chase Quigley [create.c] \n\nint main (int argc, char *argv[]) {\n\n\treturn 0;\n\n}");    
    fclose(fp);
    // Check to see if user wants a makefile created (DEFAULT IS NO)
    if (argc >= 3 && (argv[2][0] == '-' && argv[2][1] == 'm')) {
        FILE *fp2 = fopen("makefile", "w");
        fprintf(fp2, "GCC = gcc\nCFLAGS = -o\nRM = rm -f\n\ndefault:all\n\nall:%s\n\n%s:%s.c\n", NAME, NAME, NAME);
        fclose(fp2); 
        return 0;
    } else {
        return 0;
    }
}

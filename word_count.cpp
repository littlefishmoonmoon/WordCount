#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE* file = fopen("E://code//WordCount//input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int charCount = 0;
    int wordCount = 0;
    bool inWord = false;

    char c;
    while ((c = fgetc(file)) != EOF) {
        charCount++; // ��ȡ��ÿ���ַ��������ַ���

        // �����ǰ�ַ��Ƕ��Ż�ո񣬲�������֮ǰ��һ�������У������ǽ�����һ������
        if ((c == ',' || c == ' ') && inWord) {
            inWord = false;
        }

        // �����ǰ�ַ����Ƕ���Ҳ���ǿո񣬲�������֮ǰ���ڵ����У������ǿ�ʼ��һ���µ���
        if (!(c == ',' || c == ' ') && !inWord) {
            inWord = true;
            wordCount++; // ��ʼ�µ��ʣ����ӵ��ʼ���
        }
    }
    fclose(file);
    printf("Character count: %d\n", charCount);
    printf("Word count: %d\n", wordCount);

    return 0;
}


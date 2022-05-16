#include "srcc.h"

int main(void)
{

    Privacy s[20];
    int count = 0, menu;
    int index = 0;
    while (1)
    {
        menu = selectMenu();
        if (menu == 0)
            break;
        if (menu == 1)
        {
            readPrivacy(s, index);
        }
        else if (menu == 2)
        {
            if (count <= 20) //Ư�������� �ʰ��ϸ� �ȵ�
            {
                count += addPrivacy(&s[index++]); //Ư�� �迭�� �ּҸ� �����ֱ� ������ &�� �� �����!!
            }
            else
            {
                printf("�� �̻� �߰��� �� �����ϴ�.\n");
            }
        }
        else if (menu == 3)
        {
            int answer = askIndex(s, index);
            if (answer != 0)
            {
                updatePrivacy(&s[answer - 1]); // answer-1�� �ϴ� ����:  index�� 0���� �����ϱ� ����
            }
            else
            {
                printf("������ �� �����ϴ�.\n");
            }
        }
        else if (menu == 4)
        {
            int answer = askIndex(s, index);
            if (answer == 0)
            {
                printf("=> ��ҵǾ����ϴ�.\n");
                continue;
            }
            else
            {
                int delete;
                printf("������ �����Ͻðڽ��ϱ�?(���� :1)");
                scanf("%d", &delete);
                if (delete == 1)
                {
                    if (deletePrivacy(&s[answer - 1]))
                    {
                        count--;
                        printf("=> �����Ǿ����ϴ�.\n");
                    }
                }
            }
        }
        else if (menu == 5) //����� �Է� �޴�
        {
            checkCommute(s, index);
        }
        else if (menu == 6) // ����� ��ȸ
        {
            readCommute(s, index);
        }
        else if (menu == 7) // ���� ���� �޴�
        {
            saveData(s, index);
        }
        else if (menu == 8) // �˻� �޴�
        {
            findPrivacy(s, index);
        }
    }

    printf("\n==> ����Ǿ����ϴ� <==\n");
    return 0;
}
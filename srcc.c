#include "srcc.h"

char masterkey[30] = {"1234 abcd!"};

int checkMasterkey()
{
    char temp_mk[30];
    printf("?��?��?��?��?��?��絿첨?��?��?��?���? Masterkey?��?��?�� ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>\n");
    getchar();
    fgets(temp_mk, 30, stdin);
    temp_mk[strlen(temp_mk) - 1] = '\0';

    int temp = strcmp(masterkey, temp_mk);

    if (temp == 0)
        return 1;
    else
        return 0;
}

int selectMenu()
{
    int menu;
    printf("\n***** ?��?��?��?���? ?��?��?��?��?��?�� ?��?��?��?�� *****\n");
    printf("1. ?��?��?��?�� ?��?��?��?�� \n");
    printf("2. ?��?��?��?�� ?��?��곤옙 \n");
    printf("3. ?��?��?��?�� ?��?��?��?��?��?�� \n");
    printf("4. ?��?��?��?�� ?��?��?��?��?��?�� \n");
    printf("0. ?��?��?��?��?��?�� \n\n");
    printf("=> ?��?��?��?��?��?��?�� ?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��. ");
    scanf("%d", &menu);
    return menu;
}

int addPrivacy(Privacy *s) // Create
{

    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("?��?��몌옙?��?��?�� ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%s", s->name);
        printf("?��?��?��?��?��몌옙 ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%d", &s->age);
        printf("?��?��?��?��?��?��?��?��?��?��?�� ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%s", s->phone_num);
        printf("?��?��?��책占?��?�� ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%s", s->position);
        printf("?��?��?��?��?��?��?��?��?��?��?��?��?�� ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%d", &s->special_num);
        printf("?��?��?��橘占?��ｏ옙?���? ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%s", s->pwd);

        return 1;
    }
    else
    {
        printf("\nMasterkey ?��?��?�� ?��?��?��?��?��?��!!\n");
        return 0;
    }
}
// Read ?��?��?��?��
void readPrivacy(Privacy *s, int count)
{
    int temp = checkMasterkey();
    if (temp == 1)
    {
        printf("\nNo Position Name Age  Phone_num    Speicial_num  Pwd \n");
        printf("====================================================\n");
        for (int i = 0; i < count; i++)
        {
            if (s[i].age == -1)
                continue;
            printf("%2d ", i + 1);
            read_OnePrivacy(s[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nMasterkey?��?��?�� ?��?��?��?��?��?��!!\n");
    }
}
void read_OnePrivacy(Privacy s)
{
    printf("%4s %6s %4d %10s %8d %10s\n", s.position, s.name, s.age, s.phone_num, s.special_num, s.pwd);
}
int updatePrivacy(Privacy *s) // Update
{
    int temp = checkMasterkey();

    if (temp == 1)
    {
        printf("?��?��?��?��?��?��?�� ?��?��몌옙?��?��?�� ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%s", s->name);
        printf("?��?��?��?��?��?��?�� ?��?��?��?��?��몌옙 ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%d", &s->age);
        printf("?��?��?��?��?��?��?�� ?��?��?��?��?��?��?��?��?��?��?�� ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%s", s->phone_num);
        printf("?��?��?��?��?��?��?�� ?��?��?��책占?��?�� ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%s", s->position);
        printf("?��?��?��?��?��?��?�� ?��?��?��橘占?��ｏ옙?���? ?��?��뤄옙?��?��?��?��?��?��?��?��?��?�� =>");
        scanf("%s", s->pwd);
        printf("==> ?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��?�� <== \n");

        return 1;
    }
    else
    {
        printf("\nMasterkey?��?��?�� ?��?��?��?��?��?��!!\n");
        return 0;
    }
}

int deletePrivacy(Privacy *s) // Delete
{
    int temp = checkMasterkey();
    if (temp == 1)
    {
        s->age = -1; //?��?��?��?��?��곤옙 ?��?��?��?��?��?��?��?��?�� ?��?��?��?�� ?��?��?��?��?��?�� ?��?��?��?��?��?�� ?��?��?��?��?��?��
        return 1;
    }
    else
    {
        printf("\nMasterkey?��?��?�� ?��?��?��?��?��?��!!\n");
        return 0;
    }
}

int askIndex(Privacy *s, int count)
{
    int answer;

    readPrivacy(s, count);
    printf("?��?��?��?��?��?��?�� (?��?��?��?���? :0)? ");
    scanf("%d", &answer);
    return answer;
}

void checkCommute(Privacy *s, int count)
{
    int num = 0;         //?��?��?��洹� �솗�씤
    int flag = 0;        //??�좎???踰덊?�����? ?��꾨��踰?��?��?���? �옒 �엯�젰�뻽�뒗吏� �솗�씤
    int i = 0;           //諛섎?��?���? 蹂��닔
    int tmp_special_num; //�엫�떆 ??�좎???踰덊?��
    char tmp_pwd[30];    //�엫�떆 �뙣�뒪�썙�뱶

    printf("?��?��?���씠硫� 1�쓣 �엯�젰�븯??�� �눜洹쇱?��硫� 2?���? �엯�젰�빐二쇱�?�슂!\n");
    scnaf("%d", &num);
    if (!(num == 1 || num == 2))
    {
        printf("踰덊?��?���? �옒紐� �늻?��?��??��?���땲�떎.\n");
        return;
    }
    printf("??�좎???踰덊?��?���? �엯�젰�빐二쇱�?�슂!\n");
    scanf("%d", &tmp_special_num);
    getchar();
    printf("?��꾨��踰?��?��?���? �엯�젰�빐二쇱�?�슂!\n");
    scanf("%s", tmp_pwd);

    for (; i < count; i++)
    {
        if (s[i].special_num == tmp_special_num)
        {
            if (strcmp(s[i].pwd, tmp_pwd) == 0)
            {
                flag = 1; //李얠�?�떎�뒗 �쓽誘�
                break;
            }
        }
    }

    if (flag == 1 && num == 1)
    { //�룄李⑹?��媛꾩?�� ����?���븯硫� �맖
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].arrive_time_hour = tm.tm_hour;
        s[i].arrive_time_min = tm.tm_min;
        s[i].arrive_time_sec = tm.tm_sec;
        printf("�떆媛꾩?�� �꽦??�듭?���쑝濡� ����?���븯����?���땲�떎\n");
        return;
    }
    if (flag == 1 && num == 2)
    { //�뼚�궃�떆媛꾩?�� ����?���븯硫� �맖
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        s[i].leave_time_hour = tm.tm_hour;
        s[i].leave_time_min = tm.tm_min;
        s[i].leave_time_sec = tm.tm_sec;
        printf("�떆媛꾩?�� �꽦??�듭?���쑝濡� ����?���븯����?���땲�떎\n");
        return;
    }
}

void seeTime(Privacy *s, int count)
{
    int scnt = 0;
    char search[20];

    printf("�˻��� �̸�? ");
    scanf("%s", search);
    printf("*********************\n");
    for (int i = 0; i < count; i++)
    {
        if (s[i].age == -1)
            continue;
        if (strstr(s[i].name, search))
        {
            printf("%2d", i + 1);
            readScore(s[i]);
            scnt++;
        }
    }
    if (scnt == 0)
        printf("==> �˻��� ������ ����");
    printf("\n");
}
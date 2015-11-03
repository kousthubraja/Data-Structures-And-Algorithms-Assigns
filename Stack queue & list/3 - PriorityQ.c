//This one is copied from ma friend... not my code :P
#include <stdio.h>

int h_size=0;
struct PQ
{
    int el;
    int pr;
};
struct PQ s[100],t,f;
void MinHeapify();


int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return (2*i+1);
}
void MinHeapify(int i)
{
    int l,r,small;
    l=left(i);
    r=right(i);
    if(l<=h_size && ((s[l].pr)<(s[i].pr)))
    small=l;
    else
    small=i;
    if(r<=h_size && ((s[r].pr)<(s[small].pr)))
    small=r;
    if(small!=i)
    {
        struct PQ t=s[i];
        s[i]=s[small];
        s[small]=t;
        MinHeapify(small);
    }
}
void BuildHeap()
{
    int i, l=h_size;
    for(i=l/2;i>=1;i--)
    MinHeapify(i);
}

void heap_insert(struct PQ t)
{

    h_size++;
    s[h_size].el=t.el;
    s[h_size].pr=t.pr;
    BuildHeap();
}

struct PQ heap_remove()
{
    f=s[1];
    struct PQ t=s[1];
    s[1]=s[h_size];
    s[h_size]=t;

    h_size--;
    BuildHeap();
    return f;
}

struct PQ peek()
{
    f=s[1];
    return f;
}

void increase_priority(struct PQ t)
{
    int i, found=0;
    for(i=1;i<=h_size;i++)
    {
        if(s[i].el==t.el)
        {
            found=1;
            if(t.pr>s[i].pr)
            {

                break;
            }
            s[i].pr=t.pr;
            BuildHeap();
            break;
        }
    }
    if(found==0)
        printf("EMPTY\n");

}

int main()
{
    int option;
    do
    {
        scanf("%d", &option);
        switch(option)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                scanf("%d %d", &t.el, &t.pr);

                if(t.el<0 || t.pr<1)
                {
                    printf("Invalid\n");
                    break;
                }
                heap_insert(t);
                break;
            }
            case 2:
            {
                if(h_size==0)
                {
                    printf("EMPTY\n");
                    break;
                }
                else
                {
                    struct PQ tmp = heap_remove();
                    printf("%d (%d)\n", tmp.el, tmp.pr);
                    break;
                }
            }
            case 3:
            {
                if(h_size==0)
                {
                    printf("EMPTY\n");
                    break;
                }
                else
                {
                    struct PQ tmp = peek();
                    printf("%d (%d)\n", tmp.el, tmp.pr);
                    break;
                }
            }
            case 4:
            {
                if(h_size==0)
                {
                    printf("EMPTY\n");
                    break;
                }
                else
                {

                    scanf("%d", t.el);
                    scanf("%d", t.pr);
                    if(t.el<0 || t.pr<1)
                    {
                        printf("Invalid\n");
                        break;
                    }
                    increase_priority(t);
                    break;
                }
            }
            default:
            {
                printf("Invalid");
                return 0;
            }
        }
    }while(1);

    return 0;
}

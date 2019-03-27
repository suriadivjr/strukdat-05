/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : Exercise-05
Tahun           : 2019
*/

#include <iostream>
using namespace std;

struct Pembalap
{
   int nomor;
   char nama;
   int waktu;
   Pembalap* next;
   Pembalap* prev;
};

void createNode(Pembalap* &p,  int nomor, char nama)
{
 	p=new Pembalap;
 	p->nomor=nomor;
 	p->nama=nama;
 	p->waktu=0;
 	p->next=NULL;
 	p->prev=NULL;
}

void insertFirst(Pembalap* &head, Pembalap* node)
{
	if (head==NULL) head=node;
 	else 
	{
  		node->next=head;
  		head->prev=node;
  		head=node;
 	}
}

void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node)
{
	Pembalap* pBantu=head;
	if (head->nomor==nomorKey)
	{
		node->next=head;
		head->prev=node;
		head=node;
	}
	else
	{
		while(pBantu!=NULL)
		{
			if(pBantu->nomor==nomorKey)
			{
				node->next=pBantu;
				node->prev=pBantu->prev;
				pBantu->prev->next=node;
				pBantu->prev=node;
				break;
			}
			else
			{
				pBantu=pBantu->next;
			}
		}
	}
}

void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode)
{
    Pembalap* pBantu=head;
    if (head->nomor==nomorKey)
	{
        deletedNode=head;
        head=head->next;
        head->prev=NULL;
        deletedNode=NULL;
    }
    else
	{
        while(pBantu!=NULL)
		{
            if(pBantu->nomor==nomorKey)
			{
                pBantu->prev->next=pBantu->next;
                pBantu->next->prev=pBantu->prev;
                deletedNode=pBantu;
                deletedNode=NULL;
                break;
            }
            else
                pBantu=pBantu->next;
        }
    }
}

void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate)
{
	pToUpdate=firstNode;
 	while (pToUpdate->nomor!=nomorKey) pToUpdate=pToUpdate->next;
}

void traversal(Pembalap* head)
{
	Pembalap* pBantu=head;
 	if (pBantu==NULL) 
	{
  	cout << "LIST KOSONG";
 	}
	else 
	{
  		while (pBantu!=NULL) 
		{
   			cout << "Nomor: " << pBantu->nomor << endl;
   			cout << "Nama: " << pBantu->nama << endl;
   			cout << "Waktu: " << pBantu->waktu << endl << endl;
   			pBantu=pBantu->next;
  		}
 	}
}

/*
void sortingByNomor(Pembalap* &head)
{
	Pembalap* temp1;
	Pembalap* temp2;
	if(head==NULL)
	{
		cout<<"LIST KOSONG";
	}
	else
	{
		Pembalap* pBantu=head;
		while(pBantu!=NULL)
		{
			if(pBantu->nomor>pBantu->next->nomor)
			{
				if(pBantu->prev==NULL)
				{
					temp1=pBantu->next->next;
					pBantu->next->next->prev=pBantu;
					pBantu->prev=pBantu->next;
					pBantu->next->prev=NULL;
					pBantu->next->next=pBantu;
					pBantu->next=temp1;
				}
				else if(pBantu->next==NULL)
				{
					
				}
				else
				{
					pBantu->next->next->prev=pBantu;
					pBantu->prev->next=pBantu->next;
					pBantu->next=pBantu->next->next;
					pBantu->next->prev=pBantu->prev;
					pBantu->prev=pBantu->next;
					pBantu->prev->next=pBantu;
				}
			}
			pBantu=pBantu->next;
		}
	}
}
*/

void update(Pembalap* firstNode, int nomorKey)
{
    Pembalap* pBantu=firstNode;

    search(firstNode,nomorKey,pBantu);
    pBantu->nama='k';
    pBantu->nomor=24;
    pBantu->waktu=10;

    cout << "Nama: " << pBantu->nama<<endl;
    cout << "Nomor: " << pBantu->nomor<<endl;
    cout << "Waktu: " << pBantu->waktu<<endl<<endl;

}


int main(int argc, char** argv) 
{
	Pembalap* head = NULL;
 	Pembalap* pBaru = NULL;
 	Pembalap* pToUpdate = NULL;
 	char nama = 'a';

 	for (int i = 0; i < 4; i++) 
	{
   		createNode(pBaru, i+1, nama++);
   		insertFirst(head, pBaru);
 	}

 	cout << "\n>>> List" << endl;
 	traversal(head);

 	int keyNomor = 2;
 	cout << "\n>>> Insert Before nomor " << keyNomor << endl;
 	createNode(pBaru, 99, 'z');
 	insertBefore(head, keyNomor, pBaru); 
 	traversal(head);

	/*
	cout << "\n>>> SortingByNomor" << endl;
 	sortingByNomor(head);
 	traversal(head);
	*/

	keyNomor = 3;
 	cout << "\n>>> Delete nomor " << keyNomor << endl;
 	Pembalap* pHapus = NULL;
 	deleteByKey(head, keyNomor, pHapus);
 	traversal(head);

 	keyNomor = 4;
 	cout << "\n>>> Update nomor " << keyNomor << endl;
 	update(head, keyNomor);
	
 	cout << "\n>>> Updated list\n";
 	traversal(head);
	return 0;
}

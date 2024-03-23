// Enter your student ID and Fullname
// 22200384 ?Üê?òÅ?õÖ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
int updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 

int main(void) {
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			no = updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level

	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	size += 1;
	return size;
}

void printStatistics(struct st_channel *c[], int size)
{
    printf("> Statistics of Channels\n");
    int count[5] = {0};        // Number of channels in each level
    long long int total[5] = {0};  // Total number of subscribers in each level
    char topChannel[5][100];   // Top channel in each level
    int maxCount[5] = {0};     // Maximum subscribers in each level

    // Calculate statistics for each channel
    for (int i = 0; i < size; i++)
    {
        int level = c[i]->level;
        count[level]++;
        total[level] += c[i]->count;
        if (c[i]->count > maxCount[level])
        {
            maxCount[level] = c[i]->count;
            strcpy(topChannel[level], c[i]->name);
        }
    }

    // Print statistics for each level
    for (int i = 0; i < 5; i++)
    {
        double average = count[i] > 0 ? (double)total[i] / count[i] : 0;
        printf("%s : %d channels, Average %.1lf peoples, Top channel : %s (%d peoples)\n",
               LNAME[i], count[i], average, topChannel[i], maxCount[i]);
    }
}


void pickupRandomChannels(struct st_channel *c[], int size)
{
    printf("> Pick up Channels\n");
    printf("> How much channels you want to pick up? > ");
    int count;
    scanf("%d", &count);

    // Validate input count
    if (count > size)
    {
        printf("Error: There are only %d channels available.\n", size);
        return;
    }

    // Pick random channels and print their details
    printf("Random Channels\n");
    for (int i = 0; i < count; i++)
    {
        int index = rand() % size;
        printf("[%d] %s (%s level, %d peoples)\n", index + 1, c[index]->name, LNAME[c[index]->level], c[index]->count);
    }
}

void searchChannel(struct st_channel *c[], int size)
{
    printf("> Search Channels\n");
    printf("> Choose one (1:by peoples 2:by names) > ");
    int option;
    scanf("%d", &option);

    if (option == 1) // Search by number of people
    {
        int from, to;
        printf("> Enter the range of peoples (from ~ to) > ");
        scanf("%d %d", &from, &to);

        printf("> Result:\n");
        int count = 0;
        // Iterate through channels and print those within the specified range
        for (int i = 0; i < size; i++)
        {
            if (c[i]->count >= from && c[i]->count <= to)
            {
                printf("[%2d] %-20s %d peoples [%s]\n", i + 1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
                count++;
            }
        }
        printf("> %d channels are found.\n", count);
    }
    else if (option == 2) // Search by name
    {
        char searchName[100];
        printf("> Enter a names > ");
        scanf("%s", searchName);

        printf("> Result:\n");
        int count = 0;
        // Iterate through channels and print those whose name contains the search string
        for (int i = 0; i < size; i++)
        {
            if (strstr(c[i]->name, searchName) != NULL)
            {
                printf("[%2d] %-20s %d peoples [%s]\n", i + 1, c[i]->name, c[i]->count, LNAME[c[i]->level]);
                count++;
            }
        }
        printf("> %d channels are found.\n", count);
    }
}


int updateChannel(struct st_channel *c[], int size)
{
    printf("> Modify a Channel\n");
    printf("> Enter a number of channel > ");
    int channelNumber;
    scanf("%d", &channelNumber);

    if (channelNumber != size + 1)
    {
        printf("> Wrong number.\n");
        return size;
    }
    printf("> Enter a new name of channel > ");
    scanf("%s", c[channelNumber - 1]->name);

    printf("> Enter a new amount of peoples > ");
    scanf("%d", &(c[channelNumber - 1]->count));

    printf("> Channel info. is modified.\n");

    // Print updated channel information
	printf("> Channel Info.\n");
    printf("[%2d] %-20s %d peoples [%s]\n", channelNumber, c[channelNumber - 1]->name, c[channelNumber - 1]->count, LNAME[c[channelNumber - 1]->level]);

    // Increment the count of channels
	size += 1;

	return size;// Return updated number of channels
}


int deleteChannel(struct st_channel *c[], int size)
{
    int channelNumber;
    int YesorNo;
    printf("> Delete a Channel\n");
    printf("> Enter a number of channel > ");
    scanf("%d", &channelNumber);

    if (channelNumber > size || channelNumber <= 0)
    {
        printf("> Wrong number.\n");
        return size;
    }
    else
    {
        printf("> Channel info.\n");
        printf("[%2d] %s %20d peoples [%s]\n", channelNumber, c[channelNumber - 1]->name, c[channelNumber - 1]->count, LNAME[c[channelNumber - 1]->level]);
        printf("Do you want to delete the channel? (1:Yes 0:No) > ");
        scanf("%d", &YesorNo);
        if (YesorNo == 1)
        {
            printf("> Channel is deleted.\n");
            for (int i = 0; i < size - 1; i++)
            {
                // Shift remaining channels to fill the gap
               if(channelNumber < i) c[i] = c[i + 1];
            }
			size -= 1;
            // Decrement the count of channels
            return size;
        }
        else if (YesorNo == 0)
        {
            printf("> Canceled.\n");
            return size;
        }
    }
}




void makeReport(struct st_channel *c[], int size)
{
    // Save all channel information into channels.txt
    FILE *file;
    file = fopen("channels.txt", "w");
    printf("> All information of channels are saved into channels.txt.\n");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%s %d\n", c[i]->name, c[i]->count);
    }
    fclose(file);

    // Save channel statistics into report.txt
    file = fopen("report.txt", "w");
    printf("> Channel Statistics are saved into report.txt.\n");
    fprintf(file, "> Statistics of Channels\n");
    for (int i = 0; i < 5; i++)
    {
        int totalChannels = 0;
        int totalPeoples = 0;
        int maxPeoples = 0;
        char topChannel[100];
        // Calculate statistics for each level
        for (int j = 0; j < size; j++)
        {
            if (c[j]->level == i)
            {
                totalChannels++;
                totalPeoples += c[j]->count;
                if (c[j]->count > maxPeoples)
                {
                    maxPeoples = c[j]->count;
                    strcpy(topChannel, c[j]->name);
                }
            }
        }
        // Write statistics to the file
        fprintf(file, "%s : %d channels, Average %.1f peoples, Top channel : %s (%d peoples)\n", LNAME[i], totalChannels, (float)totalPeoples / totalChannels, topChannel, maxPeoples);
    }
    fclose(file);
}

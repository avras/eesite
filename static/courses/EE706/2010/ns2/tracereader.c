// This program reads a ns2 trace file and
// estimates the average delay from node 0
// to node 1. 
//
// Author: Saravanan Vijayakumaran
// Date: March 7th, 2010

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int maxPacketId = 0;
    char eventType[2];
    float eventTime;
    int sourceNode, destinationNode;
    char packetType[4];
    int packetSize;
    char flags[8];
    int flowId;
    float sourceAddress, destinationAddress;
    int sequenceNumber;
    int packetId;
    float totalDelay = 0.0;
    float averageDelay;

    FILE *fp;
    // Open the trace file
    fp = fopen("out.tr", "r");
    
    // This while loop is used to find the maximum packet ID.
    // This is needed to determine the size of the arrays
    // which will store the packet generation and arrival times.
    while(fscanf(fp, "%s %f %d %d %s %d %s %d %f %f %d %d", 
                    &eventType, 
                    &eventTime, 
                    &sourceNode, 
                    &destinationNode, 
                    &eventType, 
                    &packetSize,
                    &flags, 
                    &flowId,
                    &sourceAddress, 
                    &destinationAddress, 
                    &sequenceNumber,
                    &packetId
                    ) != EOF
    )
    {
       maxPacketId = (maxPacketId < packetId)? packetId : maxPacketId;
    }
    //printf("%d\n", maxPacketId);
    
    // Dynamically allocate arrays which will hold the packet generation
    // and arrival times
    float *packetGenerationTimes, *packetArrivalTimes;
    packetGenerationTimes = (float *) malloc((maxPacketId+1)*sizeof(float));
    packetArrivalTimes = (float *) malloc((maxPacketId+1)*sizeof(float));

    int i;
    // Initialize the arrays to zero
    for(i = 0; i < maxPacketId; i++)
    {
        *(packetArrivalTimes + i) = *(packetGenerationTimes + i) = 0.0;
    }

    // Reset the file pointer to the beginning of the trace file
    rewind(fp);

    // This while loop is used to populate the arrays which hold
    // the packet generation and arrival times for packets going
    // from node 0 to node 1
    while(fscanf(fp, "%s %f %d %d %s %d %s %d %f %f %d %d", 
                    &eventType, 
                    &eventTime, 
                    &sourceNode, 
                    &destinationNode, 
                    &packetType, 
                    &packetSize,
                    &flags, 
                    &flowId,
                    &sourceAddress, 
                    &destinationAddress, 
                    &sequenceNumber,
                    &packetId
                    ) != EOF
    )
    {
        if((strcmp(&packetType[0],"cbr") == 0 ) &&
           (sourceNode == 0) &&
           (destinationNode == 1)
          )
        {
            if(strcmp(&eventType[0],"+") == 0)
            {
                //printf("+ %d %f\n", packetId, eventTime);
                *(packetGenerationTimes + packetId) = eventTime;
            }
            else if(strcmp(&eventType[0],"r") == 0)
            {
                //printf("r %d %f\n", packetId, eventTime);
                *(packetArrivalTimes + packetId) = eventTime;
            }
        }
    }

    // This loop calculates the total delay experienced by the
    // packets.
    for(i = 0; i <= maxPacketId; i++)
    {
        if(*(packetArrivalTimes+i) != 0 && *(packetGenerationTimes +i) != 0)
        {
            totalDelay += *(packetArrivalTimes + i) - *(packetGenerationTimes + i);
        }
    }

    printf("Average delay = %f\n", totalDelay/(maxPacketId+1));

    free(packetGenerationTimes);
    free(packetArrivalTimes);
    fclose(fp);
    return 0;
}

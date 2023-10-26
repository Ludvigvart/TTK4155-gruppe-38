#define NODE1_CPU 16000000UL
#define NODE2_CPU 84000000
#define BAUDRATE 125000

#define SJW 3
#define PROP_SEG 2
#define PHASE_SEG1 6
#define PHASE_SEG2 7


#define NUMBER_OF_TQ = (1+PHASE_SEG1+PHASE_SEG2+PROP_SEG);


#define NODE1_BRP = NODE1_CPU / (2*NUMBER_OF_TQ*BAUDRATE);


#define NODE2_BRP = NODE2_CPU/(NUMBER_OF_TQ*BAUDRATE);
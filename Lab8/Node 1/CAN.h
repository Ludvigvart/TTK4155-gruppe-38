#include "mcp2515.h"


void can_init(){
	mcp_init();
}

typedef struct Message{
	unsigned int id;
	uint8_t length;
	char data[8];
	}message_t, *message_ptr;
	
	
	
void can_send(message_ptr message){
	mcp_write(MCP_TXB0SIDH, message->id/8);
	mcp_write(MCP_TXB0SIDL, (message->id%8) << 5);
	
	mcp_write(MCP_TXB0DLC, message->length);
	
	for(int i = 0; i<message->length;i++){
		mcp_write(MCP_TXB0D0 + i, message->data[i]);
	}
	
	mcp_request_to_send(0);
}

message_t can_receive(){
	message_t message = {};
	
	uint8_t id_low = mcp_read(MCP_RXB0SIDL)/0b100000;
	uint8_t id_high = mcp_read(MCP_RXB0SIDH);
	message.id = id_high * 0b1000 + id_low;
	
	message.length = mcp_read(MCP_RXB0DLC);
	
	for (int i = 0; i < message.length; i++)
	{
		message.data[i] = mcp_read(MCP_RXB0D0 + i);
	}
	
	return message;
}
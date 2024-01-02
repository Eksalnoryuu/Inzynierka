#include "object_server_service.h"

void ObjectServer::Init(const std::string address)
{
	mContext = std::make_unique<zmq::context_t>(1);
	mPubSocket = std::make_shared<zmq::socket_t>(*mContext, 1);
	mSubSocket = std::make_shared<zmq::socket_t>(*mContext, 2);
	mAddress = address;
}

void ObjectServer::Connect()
{
	mSubSocket->bind(mAddress);
}

void ObjectServer::Start()
{
	while (true)
	{
		std::vector<zmq::message_t> recv_msgs;
		zmq::recv_result_t result = zmq::recv_multipart(*mSubSocket, std::back_inserter(recv_msgs));
        spdlog::info("[SERVER] Received [{}]: {}", recv_msgs[0].to_string(), recv_msgs[1].to_string());
	}
}
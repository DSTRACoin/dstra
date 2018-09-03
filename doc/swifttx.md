##BriskTX Technical Information

BriskTX has been integrated into the Core Daemon in two ways:
* "push" notifications (ZMQ and `-brisktxnotify` cmd-line/config option);
* RPC commands.

####ZMQ

When a "Transaction Lock" occurs the hash of the related transaction is broadcasted through ZMQ using both the `zmqpubrawtxlock` and `zmqpubhashtxlock` channels.

* `zmqpubrawtxlock`: publishes the raw transaction when locked via BriskTX
* `zmqpubhashtxlock`: publishes the transaction hash when locked via BriskTX

This mechanism has been integrated into Bitcore-Node-PIVX which allows for notification to be broadcast through Insight API in one of two ways:
* WebSocket: [https://github.com/PIVX-Project/insight-api-dstra#web-socket-api](https://github.com/PIVX-Project/insight-api-dstra#web-socket-api) 
* API: [https://github.com/PIVX-Project/insight-api-dstra#brisktx-transactions](https://github.com/PIVX-Project/insight-api-dstra#brisktx-transactions) 

####Command line option

When a wallet BriskTX transaction is successfully locked a shell command provided in this option is executed (`%s` in `<cmd>` is replaced by TxID):

```
-brisktxnotify=<cmd>
```

####RPC

Details pertaining to an observed "Transaction Lock" can also be retrieved through RPC, it’s important however to understand the underlying mechanism.

By default, the PIVX Core daemon will launch using the following constant:

```
static const int DEFAULT_SWIFTTX_DEPTH = 5;
```

This value can be overridden by passing the following argument to the PIVX Core daemon:

```
-brisktxdepth=<n>
```

The key thing to understand is that this value indicates the number of "confirmations" a successful Transaction Lock represents. When Wallet RPC commands are performed (such as `listsinceblock`) this attribute is taken into account when returning information about the transaction. The value in `confirmations` field you see through RPC is showing the number of `"Blockchain Confirmations" + "BriskTX Depth"` (assuming the funds were sent via BriskTX).

There is also a field named `bcconfirmations`. The value in this field represents the total number of `"Blockchain Confirmations"` for a given transaction without taking into account whether it was BriskTX or not.

**Examples**
* BriskTX transaction just occurred:
    * confirmations: 5
    * bcconfirmations: 0
* BriskTX transaction received one confirmation from blockchain:
    * confirmations: 6
    * bcconfirmations: 1
* non-BriskTX transaction just occurred:
    * confirmations: 0
    * bcconfirmations: 0
* non-BriskTX transaction received one confirmation from blockchain:
    * confirmations: 1
    * bcconfirmations: 1

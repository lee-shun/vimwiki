# 如何在px4中打印消息。。

## 在模块的头文件加入

    #include <uORB/topics/mavlink_log.h>
    
    orb_advert_t mavlink_log_pub{nullptr};
    
## 在模块的cpp中加入

    #include <systemlib/mavlink_log.h>
    
## 打印消息

    mavlink_log_info(&mavlink_log_pub,"value:%f\n",double(value));

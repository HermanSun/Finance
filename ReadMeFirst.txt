解释说明及注意事项：

做monte carlo simulation的时候用到了VBA程序，所以一定记得要保存为xlsm格式并且在“文件->选项->信任中心->宏”设置中选择为信任宏

根据price可以算出simple return和log return的相关数据，我都算出来并且列在了5.1.1中。因为5.1.2要求用discretized model，所以5.1.2中的return相关数据都用的是simple return；而5.2.1要求用BSM，所以5.2.1中的return相关数据都用的是log return

“5.1.2 Random Error”表单是用正态分布生成的error；“5.1.2 Return”表单是计算的mu*dt + sigma*dt*error作为随机的return；“5.1.2 Result”是根据题目要求求出的完整结果

5.1.2中我用的是2018年4月30号作为预测数据的第0天，也就是开始预测的最初基础日期。这个信息不知道会不会影响你之后的题目，所以就先告知你好了。
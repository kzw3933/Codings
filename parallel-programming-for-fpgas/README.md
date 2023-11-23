# FPGA并行编程

## HLS的使用

### 常用概念
```markdown
在Vitis HLS中综合结果报告中的一些术语的含义如下：

1. Latency：指的是完成一个操作所需的时钟周期数。在综合报告中，Latency是指整个设计在给定时钟频率下的最短执行时间。一般来说，Latency越短，设计的性能就越好。

2. Iteration Latency：指的是完成一个循环迭代所需的时钟周期数。在综合报告中，Iteration Latency是指循环的一次迭代所需的最短执行时间。Iteration Latency与设计中的循环相关。

3. Interval：指的是两次操作之间的时间间隔，通常是指两次迭代之间的时间间隔。Interval通常与设计中的循环相关，也可以用来衡量设计的吞吐量。

4. Trip Count：指的是循环迭代的次数。在综合报告中，Trip Count是指循环的总迭代次数。

5. Pipelined：指的是设计中是否使用了流水线技术。在综合报告中，Pipelined是指设计中是否存在流水线寄存器，它可以提高设计的时钟频率和吞吐量。如果设计被标记为Pipelined，那么设计中的某些操作可以在同一个时钟周期内执行。

在Vitis HLS中联合仿真结果报告中的一些术语的含义如下：

1. Avg II：指的是平均迭代间隔，也称为平均II（Iteration Interval）。在联合仿真报告中，Avg II是指设计中所有循环迭代的平均执行时间。平均II越短，设计的性能就越好。

2. MAX II：指的是最长迭代间隔，也称为最大II（Iteration Interval）。在联合仿真报告中，MAX II是指设计中所有循环迭代的最长执行时间。MAX II越短，设计的性能就越好。

3. MIN II：指的是最短迭代间隔，也称为最小II（Iteration Interval）。在联合仿真报告中，MIN II是指设计中所有循环迭代的最短执行时间。MIN II越短，设计的性能就越好。

4. Avg Latency：指的是平均延迟时间。在联合仿真报告中，Avg Latency是指设计中所有操作的平均执行时间。平均延迟时间越短，设计的性能就越好。

5. MAX Latency：指的是最长延迟时间。在联合仿真报告中，MAX Latency是指设计中所有操作的最长执行时间。MAX Latency越短，设计的性能就越好。

6. MIN Latency：指的是最短延迟时间。在联合仿真报告中，MIN Latency是指设计中所有操作的最短执行时间。MIN Latency越短，设计的性能就越好。
```
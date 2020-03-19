## xv6_MFQ

Optimized the round-robin xv6 scheduler by implementing a Multi-Level Feedback Queue. Includes an aging mechanism to address starvation of processes. Also added a new pstat structure to the kernel to maintain important metrics of scheduling performance.

#### Running the Code

1. Clone repository
2. Run ```make-qemu```
3. Run test1, test2 and test3 executables for visual depiction of improed performance.

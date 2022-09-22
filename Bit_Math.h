#define SetBit(num, bit) (num)|(1<<bit)
#define ClearBit(num, bit) (num)&(~(1<<bit))
#define Toggle(num, bit) (num)^(1<<bit)
#define GetBit(num, bit) ((num&(1<<bit)) != 0)


clear all;
sample=[
        1,2 ;
        2,4 ;
        3,5;
        1,1 ;
        2,2 ;
        5,6;
        ];
label=[
        1;
        1;
        1;
        -1;
        -1;
        -1
];
plot(sample(1:3,1),sample(1:3,2),'*r');
hold on
plot(sample(4:6,1),sample(4:6,2),'+g');
hold on
axis([-10 10 -10 10]);
sample_num=6;  %样本数量
w=zeros(1,2); %权值
b=0; %偏置
d=0; %期望输出
y=0; %实际输出
error=0.00001;
step=0.001;   %学习速率
temple=0;
train_finished=0;
count=0;

while (train_finished==0)
    for n=1:sample_num
        train_finished=1;
        temple=label(n,1)*(w(1,1)*sample(n,1)+w(1,2)*sample(n,2)+b);
        if(temple<=0)
            train_finished=0;
            w(1,1)=w(1,1)+step*label(n,1)*sample(n,1);
            w(1,2)=w(1,2)+step*label(n,1)*sample(n,2); 
            b=b+step*label(n,1);
            count=count+1;
            break;
        end
    end

   if(count>=10000)
      disp('迭代次数超出限制，失败！目标非线性可分');
      train_finished=1;
   end
 
end
disp('迭代次数:');
disp(count);

test_x=-10:0.001:10;
test_y=-(w(1,1)/w(1,2))*test_x-b/w(1,2);
plot(test_x,test_y,'b');
hold on

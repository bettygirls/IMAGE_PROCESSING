```
      select 
          student.name,
          grades.math
      from
          student,grades
      where
          student.id = grades.id
```
#### inner join  取交集
在查询的几个表中，每个表都存在至少一个匹配时， INNER JOIN 关键字返回行，也就是共有部分即几个表的交集
```
      select
          student.name,
          grades.math
      from
          student
      inner join
          grades
      on 
          student.id = grades.id
```
#### left join  
关键字会从左表返回所有的行，即使右表中没有对应的行
```
      select
          student.name,
          grades.math
      from
          student
      left join
          grades
      on 
          student.id = grades.id
```
#### right join
关键字会从右表返回所有的行，即使右表中没有对应的行
```
select
    student.name,
    grades.math
from
    student
right join
    grades
on 
    student.id = grades.id
```
#### full join  取并集
```
      select
          student.name,
          grades.math
      from
          student
      full join
          grades
      on 
          student.id = grades.id
```
#### union  合并两个或者多个SELECT语句的结果集
union 和 union all 的区别： union all 会列出所有结果，有重复， union 没有重复

```
    select
        student.name,
        grades.math
    from
        student
    left join
        grades
    on 
        student.id = grades.id
    union
    select
        student.name,
        grades.math
    from
        student
    right join
        grades
    on
        student.id = grades.id
```
#### 总结
+ INNER JOIN: 如果查询的表中都有至少一个匹配，则返回行
+ LEFT JOIN: 即使右表中没有匹配，也从左表返回所有的行
+ RIGHT JOIN: 即使左表中没有匹配，也从右表返回所有的行
+ FULL JOIN: 只要其中一个表中存在匹配，就返回行
+ UNION:合并多个SELECT 语句的结果集

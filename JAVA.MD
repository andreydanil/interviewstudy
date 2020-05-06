# Java Interview Tips
## Threads 
### There are two ways to create a thread:
1. Extends Thread class. Create a thread by a new class that extends Thread class and create an instance of that class. 
2. Implementing the Runnable Interface. The easiest way to create a thread is to create a class that implements the runnable interface.

This depends on the version of Java you use. But in the end, the Big-O time complexity is still O(N*log(N)). The sorting algorithm is a modified mergesort (in which the merge is omitted if the highest element in the low sublist is less than the lowest element in the high sublist)


## Singleton Class in Java
In object-oriented programming, a singleton class is a class that can have only one object (an instance of the class) at a time.
After first time, if we try to instantiate the Singleton class, the new variable also points to the first instance created. So whatever modifications we do to any variable inside the class through any instance, it affects the variable of the single instance created and is visible if we access that variable through any variable of that class type defined.
To design a singleton class:

Make constructor as private.
Write a static method that has return type object of this singleton class. Here, the concept of Lazy initialization is used to write this static method.
Normal class vs Singleton class: Difference in normal and singleton class in terms of instantiation is that, For normal class we use constructor, whereas for singleton class we use getInstance() method (Example code:I). In general, to avoid confusion we may also use the class name as method name while defining this method (Example code:II).


## Java HashMap class
Java HashMap class hierarchy
Java HashMap class implements the map interface by using a hash table. It inherits AbstractMap class and implements Map interface.

Points to remember
```Java HashMap class contains values based on the key.
Java HashMap class contains only unique keys.
Java HashMap class may have one null key and multiple null values.
Java HashMap class is non synchronized.
Java HashMap class maintains no order.
The initial default capacity of Java HashMap class is 16 with a load factor of 0.75.
Hierarchy of HashMap class
HashMap class extends AbstractMap class and implements Map interface.
```

HashMap class declaration
Let's see the declaration for `java.util.HashMap` class.

## Streams
Parallel streams divide the provided task into many and run them in different threads, 
utilizing multiple cores of the computer. On the other hand sequential streams work just like for-loop using a single core.

The tasks provided to the streams are typically the iterative operations performed on the elements of a collection or array or from other dynamic sources. Parallel execution of streams run multiple iterations simultaneously in different available cores.


A parallel stream has a much higher overhead compared to a sequential one. Coordinating the threads takes a significant amount of time.
1. I would use sequential streams by default and only consider parallel ones if
2. I have a massive amount of items to process (or the processing of each item takes time and is parallelizable)
3. I have a performance problem in the first place
4. I don't already run the process in a multi-thread environment (for example: in a web container, if I already have many requests to process in parallel, adding an additional layer of parallelism inside each request could have more negative than positive effects)


Synchronization is the easiest and most widely used tool for thread safety in java.
Use of Atomic Wrapper classes from java.util.concurrent.atomic package. For example AtomicInteger
Use of locks from java.util.concurrent.locks package.
Using thread safe collection classes, check this post for usage of ConcurrentHashMap for thread safety.
Using volatile keyword with variables to make every thread read the data from memory, not read from thread cache.
Java synchronized
Synchronization is the tool using which we can achieve thread-safety, JVM guarantees that synchronized code will be executed by only one thread at a time. java keyword synchronized is used to create synchronized code and internally it uses locks on Object or Class to make sure only one thread is executing the synchronized code.

Java synchronization works on locking and unlocking of the resource before any thread enters into synchronized code, it has to acquire the lock on the Object and when code execution ends, it unlocks the resource that can be locked by other threads. In the meantime, other threads are in wait state to lock the synchronized resource.
We can use synchronized keyword in two ways, one is to make a complete method synchronized and another way is to create synchronized block.
When a method is synchronized, it locks the Object, if method is static it locks the Class, so it’s always best practice to use synchronized block to lock the only sections of method that needs synchronization.
While creating a synchronized block, we need to provide the resource on which lock will be acquired, it can be XYZ.class or any Object field of the class.
synchronized(this) will lock the Object before entering into the synchronized block.
You should use the lowest level of locking, for example, if there are multiple synchronized block in a class and one of them is locking the Object, then other synchronized blocks will also be not available for execution by other threads. When we lock an Object, it acquires a lock on all the fields of the Object.
Java Synchronization provides data integrity on the cost of performance, so it should be used only when it’s absolutely necessary.
Java Synchronization works only in the same JVM, so if you need to lock some resource in multiple JVM environment, it will not work and you might have to look after some global locking mechanism.
Java Synchronization could result in deadlocks, check this post about deadlock in java and how to avoid them.
Java synchronized keyword cannot be used for constructors and variables.
It is preferable to create a dummy private Object to use for the synchronized block so that it’s reference can’t be changed by any other code. For example, if you have a setter method for Object on which you are synchronizing, it’s reference can be changed by some other code leads to the parallel execution of the synchronized block.
We should not use any object that is maintained in a constant pool, for example String should not be used for synchronization because if any other code is also locking on same String, it will try to acquire lock on the same reference object from String pool and even though both the codes are unrelated, they will lock each other.
Here are the code changes we need to do in the above program to make it thread-safe.

## SOLID Principles
A short explanation of the 5 SOLID principles for object-oriented programming. The principles are:
* Single Responsibility
* Open / Closed
* Liskov Substitution
* Interface Segregation
* Dependency Inversion

These were grouped by Robert C. Martin, who invented 1), 4) and 5). 2) was formulated by Bertrand Meyer and 3) by Barbara Liskov. The acronym was coined by Michael Feathers.
Content of the 1-Pager:

#### Single Responsibility Principle
Each class has a single purpose. All its methods should relate to function.
Reasoning: Each responsibility could be a reason to change a class in the future. Fewer responsibilities -> fewer opportunities to introduce bugs during changes.
Example: Split formatting & calculating of a report into different classes.

#### Open / Closed Principle
Classes (or methods) should be open for extension and closed for modification. Once written they should only be touched to fix errors.
 New functionality should go into new classes that are derived. This is popularly interpreted to advocate inheriting from an abstract base class.
Reasoning: Again you lower the odds of breaking existing code.

#### Liskov Substitution Principle
You should be able to replace an object with any of its derived classes. Your code should never have to check which 
sub-type its’s dealing with.
Reasoning: Prevents awkward type checking and weird side-effects.

#### Interface Segregation Principle
Define subsets of functionality as interfaces.
Reasoning: Small, specific interfaces lead to a more decoupled system than a big general-purpose one.
Example: A Persistence Manager implements DBReader & DBWriter.

#### Dependency Inversion Principle
High-level modules should not depend on low-level modules. Instead, both should depend on abstractions. Abstractions should not depend on details. Details should depend upon abstractions.
Reasoning: High-level modules become more reusable if they are ignorant of low-level module implementation details.
Examples: 
1) Dependency Injection, 
2) Putting high-level modules in different packages than the low-level modules it uses.

## The Twelve Factors
* I. Codebase
One codebase tracked in revision control, many deploys
* II. Dependencies
Explicitly declare and isolate dependencies
* III. Config
Store config in the environment
* IV. Backing services
Treat backing services as attached resources
* V. Build, release, run
Strictly separate build and run stages
* VI. Processes
Execute the app as one or more stateless processes
* VII. Port binding
Export services via port binding
* VIII. Concurrency
Scale out via the process model
* IX. Disposability
Maximize robustness with fast startup and graceful shutdown
* X. Dev/prod parity
Keep development, staging, and production as similar as possible
* XI. Logs
Treat logs as event streams
* XII. Admin processes

## ExecutorService and Completable Futures
Run admin/management tasks as one-off processes
ExecutorService is a framework provided by the JDK which simplifies the execution of tasks in asynchronous mode. Generally speaking, ExecutorService automatically provides a pool of threads and API for assigning tasks to it.
Because ExecutorService is an interface, an instance of any its implementations can be used. There are several implementations to choose from in the `java.util.concurrent` package or you can create your own.
For example, the ThreadPoolExecutor class has a few constructors which can be used to configure an executor service and its internal pool.

```ExecutorService executorService = 
  new ThreadPoolExecutor(1, 1, 0L, TimeUnit.MILLISECONDS,   
  new LinkedBlockingQueue<Runnable>());
```
You may notice that the code above is very similar to the source code of the factory method `newSingleThreadExecutor()`. For most cases, a detailed manual configuration isn't necessary.
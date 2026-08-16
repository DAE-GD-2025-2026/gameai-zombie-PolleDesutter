I finally figure out how to add the BP_BTInjector, as in, I just coppied the node on the image.
Because uassets are .. weird, it didn't wanna import. I tried to fix this for more than 4 hours, ...

But when going through other students repo's I figured out we can use Unreal's BehaviorTree/StateTree System.
I found this a bit odd, since for FSM we kind of had to implement our own system, but who am I; I didn't go to the last few classes.

So, my plan is to make AI behavior, only using Unreals StateTree's, since I have experience with them because of GroupProjects (GlobGlobKinght), where the StateTree Logic had to be in C++.
The discovery that I can use these Unreal system is a lifesaver.


To do rapid prototyping, I am going to start with Blueprints and then convert them to C++, once it feels ready.
I am also going to be using the Blackboard with the StateTree.


August Update:
C++ StateTree are so underdocumented, so is everything for UE5 C++
But for StateTree's you need to find UE's code to check how they did it, since everything that seems
logical, just. does. not. work.

For example for (StateTree) Tasks you have a few things you can derrive from 'UStateTreeTaskBlueprintBase' and 'FStateTreeTasCommonBase'.
With the former, everything works the same as when working with Blueprint Tasks, it works seemlessly with everything else, what a mircale.
It would be a mircale, if it allowed Tick to be handled, for some unknown reason to me, Tick does not work in C++ when derriving from 'UStateTreeTaskBlueprintBase'. And yes, there's a variable 'bShouldCallTick', which when set to true should call tick(), but in practice, it doesn't???


After hours of searching, I looked at the MoveAI and other of UE's C++ Tasks, which helped a ton.
I just did not expect Unreal Engine to be such a disapointment when it comes to C++ documentation. 


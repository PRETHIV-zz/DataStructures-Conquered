package Task1;
import java.util.*;
public class Max_Heap {

	private ArrayList<Pair> container=new ArrayList<Pair>();
	
	public Pair top(){
		if(container.size()>0){
			return container.get(0);
		}
		else{
			return new Pair();
		}
	}
	
	public void add(Pair p){
		int rank=p.getrank(),ind=0;
		ArrayList<Pair> temp=new ArrayList<Pair>();
		for(ind=0;ind<container.size();ind++){
			if(container.get(ind).getrank()<rank){
				break;
			}
			temp.add(container.get(ind));
		}
		
		temp.add(p);
		
		while(ind<container.size()){
			temp.add(container.get(ind));
			ind++;
		}
		
		container=temp;
		
	}
	
	public int size(){
		return container.size();
	}
	
	public void inc(int i){
		Pair p=container.get(i);
		p.incrank();
		container.remove(i);
		add(p);
	}
	
	public Pair get(int i){
		return container.get(i);
	}
	
	public boolean Contains(Pair p){
		String str=p.getchar();
		for(int i=0;i<container.size();i++){
			Pair temp=container.get(i);
			if(temp.getchar().equalsIgnoreCase(str)){
				return true;
			}
		}
		return false;
	}
	
	public int getindex(Pair p){
		String str=p.getchar();
		for(int i=0;i<container.size();i++){
			Pair temp=container.get(i);
			if(temp.getchar().equalsIgnoreCase(str)){
				return i;
			}
		}
		return -1;
	}

}

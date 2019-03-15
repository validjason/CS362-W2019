
import java.util.ArrayList;
import java.util.List;
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }



	public void testManualTest() {
		String testUrl = "";
		List<String> failure = new ArrayList<String>();
		UrlValidator urlVal = new UrlValidator(null, null, 0);

		//failing
		testUrl = "www.google.com";
		boolean expected = true;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "ww.google.com";
		expected = false;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "http://www.google.com";
		expected = true;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "htp://www.google.com";
		expected = false;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "http://255.255.255.255";
		expected = true;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}
		//failing
		testUrl = "http://256.256.256.256";
		expected = false;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "http://255.255.255.255:65535";
		expected = true;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "http://255.255.255.255:65536";
		expected = false;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "http://www.google.com/";
		expected = true;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "http://www.google.com//";
		expected = false;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "http://www.google.com/?action=edit&mode=up";
		expected = true;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}

		testUrl = "http://www.google.com/?act=edit&mode=up";
		expected = false;
		if(urlVal.isValid(testUrl) != expected){
			failure.add(testUrl);
		}


		if(failure.size() > 0) {
			System.out.println("Manual Test failures: ");
			System.out.println(failure);
		}
		else if(failure.size() < 1) {
			System.out.println("Manual Tests Passed");
		}
	}




	public void testSchemePartition() {
   		//You can use this function to implement your First Partition testing
	 	boolean expected = true;
	 	List<String> failure = new ArrayList<String>();
	 	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	 	String testUrl = "";
	 
	 	for(int i = 0; i < testScheme.length; i++) {
		 	testUrl = testScheme[i].item + "www.google.com";
		 	expected = testScheme[i].valid;
		 
		 	if(urlVal.isValid(testUrl) != expected) {
			 	failure.add(testScheme[i].item);
		 	}
	 	}
	 	if(failure.size() > 0) {
		 	System.out.println("Scheme partition failures: ");
		 	System.out.println(failure);
	 	}
   }
   
   public void testAuthorityPartition(){
	   //You can use this function to implement your Second Partition testing
	   boolean expected = true;
	   List<String> failure = new ArrayList<String>();
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String testUrl = "";
	   
	   for(int i = 0; i < testAuthority.length; i++) {
		   testUrl = "http://" + testAuthority[i].item;
		   expected = testAuthority[i].valid;
		   
		   if(urlVal.isValid(testUrl) != expected) {
			   failure.add(testAuthority[i].item);
		   }
	   }
	   if(failure.size() > 0) {		//Print list of failures if any
		   System.out.println("Authority partition failures:");
		   System.out.println(failure);
	   }
   }

   public void testPortPartition(){
	   //You can use this function to implement your Second Partition testing
	   boolean expected = true;
	   List<String> failure = new ArrayList<String>();
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String testUrl = "";
	   
	   for(int i = 0; i < testPort.length; i++) {
		   testUrl = "http://www.google.com" + testPort[i].item;
		   expected = testPort[i].valid;
		   
		   if(urlVal.isValid(testUrl) != expected) {
			   failure.add(testPort[i].item);
		   }
	   }
	   if(failure.size() > 0) {		//Print list of failures if any
		   System.out.println("Port partition failures:");
		   System.out.println(failure);
	   }
   }

   public void testPathPartition(){
	   //You can use this function to implement your Second Partition testing
	   boolean expected = true;
	   List<String> failure = new ArrayList<String>();
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String testUrl = "";
	   
	   for(int i = 0; i < testPath.length; i++) {
		   testUrl = "http://www.google.com" + testPath[i].item;
		   expected = testPath[i].valid;
		   
		   if(urlVal.isValid(testUrl) != expected) {
			   failure.add(testPath[i].item);
		   }
	   }
	   if(failure.size() > 0) {		//Print list of failures if any
		   System.out.println("Path partition failures:");
		   System.out.println(failure);
	   }
   }
   
   public void testQueryPartition(){
	   //You can use this function to implement your Second Partition testing
	   boolean expected = true;
	   List<String> failure = new ArrayList<String>();
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String testUrl = "";
	   
	   for(int i = 0; i < testQuery.length; i++) {
		   testUrl = "http://www.google.com" + testQuery[i].item;
		   expected = testQuery[i].valid;
		   
		   if(urlVal.isValid(testUrl) != expected) {
			   failure.add(testQuery[i].item);
		   }
	   }
	   if(failure.size() > 0) {		//Print list of failures if any
		   System.out.println("Query partition failures:");
		   System.out.println(failure);
	   }
   }
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
		ResultPair[][] parts = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPath, testUrlQuery};
		int[] index = {0, 0, 0, 0, -1};
		UrlValidator testValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		
		int count = 0; //the number of URL's that are tested
		int trueCount = 0; //the number of URLs that that evaluate to true
		int failCount = 0; //number of URLS failed the test
		int passCount = 0; //number of invalid URLs that passed validation
		//Test every combination, until the first index has tested all parts in its pair Array
		while (index[0] != parts[0].length)
		{
			String schemeString = "";
			int current = parts.length-1; //start incrementing the last index in the array
			index[current] += 1; //increment the index test part;
			int step = current;
			/*loop when the first index is at its max, incrementing the index before it
			until reaching an index that is not at its max*/
			while(index[step] == parts[step].length && step > 0)
			{
				index[step] = 0; //reset current index from max to 0
				step -= 1;  //go to the index before it
				index[step] +=1; //increment that index
				if (index[0] == parts[0].length) //if the first index has tested all its parts
				{
					System.out.println("Results for unit based testing:");
					System.out.println("Number of tested URLs: " + count);
					System.out.println("Valid URLs: " + trueCount);
					System.out.println("Valid URL's that did not pass validation: " + failCount);
					System.out.println("Invalid URLs: " + (count - trueCount));
					System.out.println("Invalid URL's that passed validation: " + passCount + "\n");
					return;
				}
			}

			boolean isValid = true;
			count++;
			//Concatenate the parts into a string
			for (int i = 0; i < index.length; i++)
			{
				schemeString += parts[i][index[i]].item;
				if (parts[i][index[i]].valid == false)
				{
					isValid = false;
				}
			}
			if (isValid == true) {
					trueCount++;
			}
			
			boolean testResult = testValidator.isValid(schemeString);
			if (isValid != testResult) {
			   System.out.print("expected: " + isValid + " result: " + testResult + " " + schemeString);
			   //Print out the parts that should have failed if the scheme is not valid but result is valid
			   if (isValid == false)
			   {
				   passCount++; //increment the count of invalid URLS that passed validation
				   System.out.print("  Invalid parts: ");
					for (int i = 0; i < index.length; i++)
					{
						if(parts[i][index[i]].valid == false) { 
							switch(i)
							{
								case 0:
									System.out.print("Scheme:");
									break;
								case 1:
									System.out.print("Authority:");
									break;
								case 2:
									System.out.print("Port:");
									break;
								case 3:
									System.out.print("Path:");
									break;
								case 4:
									System.out.print("Query:");
									break;
	  
							}

						System.out.print(parts[i][index[i]].item + " ");	
						}
					}
			   }
			   else
			   {
				   failCount++;
			   }
			   System.out.println("");
			}
		}
   }
   
   public static void main(String[] args) {
	   UrlValidatorTest test = new UrlValidatorTest("Hello");
	   test.testIsValid();
	   test.testSchemePartition();
	   test.testAuthorityPartition();
	   test.testPortPartition();
	   test.testPathPartition();
	   test.testQueryPartition();
	   test.testManualTest();
   }
   
   static ResultPair[] testScheme = {new ResultPair("http://", true),
		   new ResultPair("http:/", false),
		   new ResultPair("http//", false),
		   new ResultPair("ht://tp", false),
		   new ResultPair("://", false),
		   new ResultPair("", false)};

   static ResultPair[] testAuthority = {new ResultPair("www.google.com", true),
	              new ResultPair("google.com", true),
	              new ResultPair("www.google", false),
	              new ResultPair("google", false),
	              new ResultPair("0.0.0.0", true),
	              new ResultPair("0.0.0", false),
	              new ResultPair("0.0.0.0.0", false),
	              new ResultPair("255.255.255.255", true),
	              new ResultPair("256.256.256.256", false),
	              new ResultPair("", false)};
   
   static ResultPair[] testPort = {new ResultPair(":80", true),
	         new ResultPair(":65535", true),
	         new ResultPair(":65536", false),
	         new ResultPair(":-1", false),
	         new ResultPair(":", true),
	         new ResultPair(":0a", false),
	         new ResultPair("", true)};
   
   static ResultPair[] testPath = {new ResultPair("/home", true),
		  new ResultPair("/home/destination", true),
	      new ResultPair("/", true),
	      new ResultPair("/..", false),
	      new ResultPair("home", false),
	      new ResultPair("/home//destination", false),
	      new ResultPair("", true)};
	
   static ResultPair[] testQuery = {new ResultPair("?action=edit", true),
	          new ResultPair("?action=edit&mode=delete", true),
	          new ResultPair("?action=", true),
	          new ResultPair("=edit", false),
	          new ResultPair("", true)};


   //Result Pairs for unit testing
   ResultPair[] testUrlScheme = {new ResultPair("http://", true),
    new ResultPair("ftp://", true),
    new ResultPair("h3t://", true),
 	new ResultPair("3ht://", false),
 	new ResultPair("http:/", false),
 	new ResultPair("http:", false),
 	new ResultPair("http/", false),
 	new ResultPair("://", false)};

	ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
		new ResultPair("www.google.com.", true),
		new ResultPair("go.com", true),
		new ResultPair("go.au", true),
		new ResultPair("0.0.0.0", true),
		new ResultPair("255.255.255.255", true),
		new ResultPair("256.256.256.256", false),
		new ResultPair("255.com", true),
		new ResultPair("1.2.3.4.5", false),
		new ResultPair("1.2.3.4.", false),
		new ResultPair("1.2.3", false),
		new ResultPair(".1.2.3.4", false),
		new ResultPair("go.a", false),
		new ResultPair("go.a1a", false),
		new ResultPair("go.cc", true),
		new ResultPair("go.1aa", false),
		new ResultPair("aaa.", false),
		new ResultPair(".aaa", false),
		new ResultPair("aaa", false),
		new ResultPair("", false)
	};
	ResultPair[] testUrlPort = {new ResultPair(":80", true),
		new ResultPair(":65535", true), // max possible
		new ResultPair(":65536", false), // max possible +1
		new ResultPair(":0", true),
		new ResultPair("", true),
		new ResultPair(":-1", false),
		new ResultPair(":65636", false),
		new ResultPair(":999999999999999999", false),
		new ResultPair(":65a", false)
	};
	ResultPair[] testUrlPath = {new ResultPair("/test1", true),
		new ResultPair("/t123", true),
		new ResultPair("/$23", true),
		new ResultPair("/..", false),
		new ResultPair("/../", false),
		new ResultPair("/test1/", true),
		new ResultPair("", true),
		new ResultPair("/test1/file", true),
		new ResultPair("/..//file", false),
		new ResultPair("/test1//file", false)
	};
	
	
	ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
		new ResultPair("?action=edit&mode=up", true),
		new ResultPair("", true)
	};
}

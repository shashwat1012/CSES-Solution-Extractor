from bs4 import BeautifulSoup
import requests

def getSolution(ques, sol):
	r = session.get(sol).content
	soup = BeautifulSoup(r, 'lxml')
	code = soup.find('pre', class_ = "linenums").get_text()
	return code

def findCorrectSolution(ques):
    r = session.get(r"https://cses.fi/problemset/view/"+ques+"/").content
    soup = BeautifulSoup(r,'lxml')
    if int(soup.find('p').string.split()[-1]) == 0: # No of submissions
        return None
    for link in soup.find_all('a', attrs = {'class':'details-link'}):
        sol = link['href']
        res = soup.find('a', href = sol, class_ ='').span['class'][2] #get status of a solution
        if res == 'full':
            return 'https://cses.fi'+sol
        return None

def createSession(username, password):
    loginData = {
		'nick': username,
		'pass': password
	} #this info will be filled in the username and password boxes which come on https://cses.fi/login

    # Session object allows one to persist certain parameters across requests.
    # It also persists cookies across all requests made from the Session instance.
    # It will use urllib3’s connection pooling.
    # Connection pooling->connections reused rather than created each time a connection is requested.
    # urllib3 is a powerful, user-friendly HTTP client for Python.
    # Variables stored in the Session object hold information about one single user.
    # Are available to all pages in one application.
    # Common information stored in session variables are name, id, and preferences.
    with requests.Session() as s: # Session obj = s
        url = 'https://cses.fi/login'
        soup = BeautifulSoup(s.get(url).content, 'lxml')
        loginData['csrf_token'] = soup.find('input', attrs = {'name':'csrf_token'})['value']
        # csrf = cross site request forging = session riding
        # csrf token prevents csrf attack
        # CSRF attack tricks the victim to do the malicious task on a victim authenticated webapplication on behalf of attackers interests.
        # CSRF attack exploits the concept that if the user has authenticated all the requests that come from that user they must be originated by the user.
        # The attacker will exploit this concept by identifying the session cookie of the session and use that to send his own payload (set of malicious codes that carry crucial information that can be used to hack any device beyond limits that you can't imagine) to run on the application.
        # Read -> https://medium.com/@charithra/introduction-to-csrf-a329badfca49
        r = s.post(url, data = loginData)
        # s.post(...) will send the data to the website which will create the session. 
        # "s" contains the actual session object for that website. 
        # "r" stores the response received for this post request.
        return s
def getQuestions():
    ques = dict()
    r = session.get(r'https://cses.fi/problemset/').content #creates raw string which deoesnt treat \... as spl char
    soup = BeautifulSoup(r, 'lxml')
    for t in soup.find_all('li', class_ = 'task'):
        quesID = t.a['href'].split('/')[-1]
        ques[quesID] =  t.a.string
    return ques

if __name__ == "__main__":
    r = requests.get("https://cses.fi/problemset/").content #content will get info in bytes
    soup = BeautifulSoup(r,'lxml')
    username = input('username: ')
    password = input('password: ')
    session = createSession(username, password)
    questions = getQuestions()
    for _ in questions:
        sol = findCorrectSolution(_)
        if not sol:
            continue
        code = getSolution(_, sol)
        ext = '.cpp'
        path = _ + ' - ' + questions[_] + ext
        file = open(path, 'w')
        file.writelines(code.split('\n'))
        file.close()

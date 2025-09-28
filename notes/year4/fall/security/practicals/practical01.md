# Practical 01

## Introduction to Security

### Description
Work through questions labelled with * during the tutorial time and other questions in your self-study time as a homework. Do them in any order you like. Ask about any during tutorials. They vary in toughness: 
- R = review question (look it up in the notes),
- E = easy (a simple application of what you learned in lectures, or something that can be found with minimal effort),
- M = moderate (may take some thought),
- H = harder (may take a lot of thought),
- O = open-ended (possibly still a research topic, or something without a standard answer).

You can let me know if you disagree with the classifications. Try to answer all of the
review questions and as many of the others as you can: this is intended to train both
your memory and develop problem-solving capabilities. Some of them are challenges
that may be harder than typical exam questions. Please let the course organizer know
if you find any typos and bugs. As a guide, if you cannot quickly answer all questions
marked R and E then you are probably not prepared for the final exam.

### Basic security concepts
1. Define the terms confidentiality, integrity and availability; Also give an implementation example for each term. [R,*]

answer
  confidentiality - the idea of preventing of unauthorised information release so information is accessible only to authorised individuals - information is encrypted
  integrity - the idea of preventing unauthorised information modification so information cannot be modified by unauthorised individuals - users must login to modify data
  availability - the idea of ensuring authorised users can access information and assets when required - unauthorised requests are blocked and ignored to not overload the system with a DDOS attack

2. What property of information resources is attacked in a denial-of-service attack? [E,*]

answer
  availability

3. Give an example of an organisation and some kind of information resource in which:
  (a) confidentiality is more important than integrity [E]
 
  answer
    Hospital - patient medical data
  (b) integrity and availability are more important than confidentiality [E]

  answer
    Public database - online library book record database

4. Think of an example in which there is a trade-off between confidentiality and availability. Give an example in which an organisation might temporarily change its behaviour to sacrifice one in order to preserve the other. [E,*]

answer
  During a cyber-attack, for example a bank may block all transactions to protect users data and assets while they resolve the issue. This sacrifices availability for confidentiality.

5. In no more than three sentences, give an example in which physical security is essential to information security. Now give an example in which information security contributes towards physical security. [E,*]

answer
  Physical security is essential for information security as if a hard drive is publicly physically available it is less secure than if it is protected with layers of physical security.
  Information security contributes to physical security with protecting individuals data, for example the location of someone in witness protection, that information must be secured or the individual could be put in danger.

6. What is a security policy? What is a security policy objective? Give an example of each. [R,*]

answer
  A security policy is a document or other that models what ought to be protected, defines which activities are or are not permitted and which information flows are or are not prohibited, and is precise, well-documented and followed. It is a high-level document while a security policy objective is a specific measurable step taken to achieve those goals.
- Organisation is commited to protect confidentiality, integrity, and availability of user data.
- Organisation implements MFA to protect user data.

7. Have a look at the University of Aberdeen information security policy. Find an example of a clause that can be interpreted (and perhaps implemented) in more than one way, and explain those different interpretations. Can you find any policies that are unlikely to be followed in practice? [O]

answer
  - "University information and digital services will be appropriately secured to protect confidentiality, integrity and availability." appropriately is very vague, is MFA obligatory is the data encrypted?
  - "All individuals within scope of this policy must complete the mandatory information security awareness training." most users will just skip through the training without paying too much attention.

8. Describe a situation in which you have experienced (or somebody you know) harm because of a failure of computer security. Which goals (Confidentiality, Integrity, and Availability) were violated? Identify: assets; vulnerabilities; threats; countermeasures. [R,*]

answer
  Hacker gained control of private account.
  - Confidentiality - attacker had access to private personal data.
  - Integrity - attacker could send messages posing as me diminishing the integrity of my online account.
  - Availability - i was locked out of my own account and could not use the service.

  - Assets - login credentials, personal data, and digital identity
  - Vulnerabilities - human error in trusting urgent-sounding account security messages, and lack of MFA
  - Threats - threat actor was hacker and threat action was social engineering
  - Countermeasures - enabling MFA and ensuring where links come from and lead to, contacting the service and asking for account recovery process

9. As above but now, consider at least one of the following services/scenarios. Consider assets value and risks and rank them (low, medium, high) from the point of view of the user and the point of view of the owner of the system. Draft in a document your findings. [O]
  1) A pharmacy using a mixture of hand-delivered prescriptions (by the patient) and electronically delivered prescriptions (by the GP practice).

  answer
    using a mixed system allows for more error as someone can clone an electronic prescription or forge a hand-delivered one easier especially if no special stationary is used or if the prescriptions are sent unencrypted. (medium) if prescription are unencrypted then patient information can be accessed without authorisation through a man in the middle attack (high)
  2) Cloud storage service providers (e.g. Dropbox, Google Drive, . . . )

  answer
    if no MFA then accounts are less secure and susceptible to phishing (high) if data is transferred unencrypted then risk of man in the middle attack (high) if data is stored unencrypted it can be leaked and cause harm to users (high)
  3) A university Virtual Learning Environment

  answer
    if this environment sets grades user grades could be modified if not secured properly (low) student files could be released and this could cause harm to student grades or even reveal sensitive research (high)

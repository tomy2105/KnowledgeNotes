# Secure Coding C#

<!-- toc -->

<!-- tocstop -->

## OWASP Top 10

### Missing Function Level Access Control

Enables performing functions user is not authorized to do due to missing or inproperly configured access checks.

The usual methods to avoid is to:
 - implement centralized, role/claim/policy based authorization system on the server (**NOT client**) preferably using builtin framework functionality
 - deny everything by default (least priviledge)
 - validate permission on every request
 - don't rely on hidding (either URLs or APIs)

In .NET Core (and newer) the common approach is to use `[Authorize]` (with optional `Roles` or `Policy`) and `[AllowAnonymous]` (**takes priority over any other authorization attribute!!!**) attributes on controller and/or actions and/or `IAuthorizationService` as a single place for authorizing all controllers.

More info:
 - [OWASP Top 10 A01:2021 – Broken Access Control](https://owasp.org/Top10/A01_2021-Broken_Access_Control/)
 - [OWASP Cheat Sheet Series - Authorization](https://cheatsheetseries.owasp.org/cheatsheets/Authorization_Cheat_Sheet.html)
 - [OWASP ASVS - V4 Access Control](https://github.com/OWASP/ASVS/blob/v4.0.3/4.0/en/0x12-V4-Access-Control.md)
 - [CWE-862](https://cwe.mitre.org/data/definitions/862.html)
 - [CWE-280](https://cwe.mitre.org/data/definitions/280.html)

### Sensitve data exposure

Data is not sufficiently protected (e.g. no encryption or poor or insufficient encryption which can be easily decrypted) which could leak to identity hijacking or financial loss.
An example would be storing data in plain text or with weak hash without salt (rainbow tables attack).

Avoid by:
 - Don't store sensitive data if not necessary
 - Always encrypt in transit and at rest with latest algorithms
 - Use strong hashing (with salt and pepper) if don't need original data or encryption if original is needed
 - Disable caching of sensitive data
 
Salt is a randomly generated string added to data (often password) as part of the hashing process. 
Pepper is a secret added to a password hash. Unlike a salt, peppers are secret and the same pepper may be reused for many hashed passwords. They must not be 
It prevents an attacker from cracking hashes and it must not be stored alongside the hashed password. 

Good password hashing algorithms:
 - Argon2 (especially Argon2id)
 - bcrypt (if Argons 2id is not available)
 - PBKDF2 (use if NIST and FIPS validation are required)
 
 In .NET Core (and newer) `PasswordHasher<TUser>` can be used and implements PBKDF2 by default or lets user extend it with custom algorithm, following packages provide other algos:
  - `Konscious.Security.Cryptography` or `Isopoh.Cryptography.Argon2` for Argon2
  - `BCrypt.Net-Next` for bcrypt

```
public class Argon2PasswordHasher<TUser> : IPasswordHasher<TUser> where TUser : User
{
    public string HashPassword(TUser user, string password)
    {
        var config = new Argon2Config();
        config.Type = Argon2Type.HybridAddressing;
        config.Version = Argon2Version.Nineteen;
        config.Password = System.Text.Encoding.UTF8.GetBytes(password);
        config.Salt = GenerateSalt();
        config.MemoryCost = 15360;
        config.TimeCost = 2;
        config.Lanes = 1;

        using var encoder = new Argon2(config);
        using var hash = encoder.Hash();
        return config.EncodeString(hash.Buffer);
    }
    
    public PasswordVerificationResult VerifyHashedPassword(TUser user, string hashedPassword, string providedPassword)
    {
        return Argon2.Verify(hashedPassword, providedPassword) ?
            PasswordVerificationResult.Success : PasswordVerificationResult.Failed;
    }
    
    public byte[] GenerateSalt()
    {
        var salt = new byte[32];
        RandomNumberGenerator.Fill(salt);
        return salt;
    }
}
```        
More info:
 - [OWASP Top 10 A02:2021 – Cryptographic Failures](https://owasp.org/Top10/A02_2021-Cryptographic_Failures/)
 - [OWASP Cheat Sheet Series - Password Storage](https://cheatsheetseries.owasp.org/cheatsheets/Password_Storage_Cheat_Sheet.html#password-hashing-algorithms)
 - [CWE-256](https://cwe.mitre.org/data/definitions/256.html)
 - [CWE-257](https://cwe.mitre.org/data/definitions/257.html)
 - [CWE-759](https://cwe.mitre.org/data/definitions/759.html)
 - [CWE-760](https://cwe.mitre.org/data/definitions/760.html)

### SQL Injection

Allowing malicious code to become a part of SQL statement without proper validation or sanitization. 
Like [Little Bobbdy droptables](https://xkcd.com/327/) where a name `Robert'; DROP TABLE Students; --` when used with query `"SELECT * FROM students WHERE name = '" + name + "'"` can lead to disasters. 

Some of the attack types:
 - Tautology attacks insert a logical statement that is always true into a query to bypass authentication or access restricted data
 - Union-based attacks inject a UNION operator into a query to combine the results of multiple queries,  allowing the attacker to access data from multiple tables (or even databases)
 - Error-based attacks inject errors into a query to potentially reveal sensitive information about the structure or content of the database inside generated error messages
 - Blind SQL injection attacks inject input into a query that causes the database to perform a specific action without revealing the results of the query, it is more difficult to detect as it does not generate any visible signs of compromise
 - Inferential SQL injection attacks inject input into a query that causes the database to perform a specific action which the attacker can observe and use to infer the results of the query
 - Second-order SQL injection attacks when an attacker can insert malicious data into a database and then subsequently cause the application to retrieve and execute that malicious data 

Always:
 - use of prepared statements (or stored procedures) and/or parameterized queries so user input is only used as a parameter at specific place
 - validate and sanitize user input because first mitigation, while preventing SQL injestion, doesn't prevent from
   - storing invalid or incorrect data in a database
   - displaying unexpected or malformed data to users
   - causing errors or unexpected behavior in an application
 - apply least priviledge on backend database user(s)
 
More info:
 - [OWASP Top 10 A03:2021 – Injection](https://owasp.org/Top10/A03_2021-Injection/)
 - [OWASP Cheat Sheet Series - SQL Injection Prevention](https://cheatsheetseries.owasp.org/cheatsheets/SQL_Injection_Prevention_Cheat_Sheet.html)
 - [CWE-20](https://cwe.mitre.org/data/definitions/20.html)
 - [CWE-89](https://cwe.mitre.org/data/definitions/89.html)

### Insufficient validation

All data should be validated. The most naive example, in finances, would be allow user to transfer a negative amount of money to other account (this steal the money from the target account).

Always:
 - assume all input is malicious and needs to be validated (including conversion to approprite type)
 - all validation and security check must be done on the server (doing on client too improves UX but must be duplicated on server too)

### Disabled security features

Security features that are disabled by default should be used (e.g. secure cookies, limiting static file serving, .....).

### Server Side Request forgery

Occurs when an attacker is able to cause a targeted server to make requests to an unintended location. An, naive, example would be proxy server that downloads some media from other server specified in the url of the request.

Such possibility opens wide possible problems like:
 - access to sensitive files
 - access to internal services/APIs
 - or simply make server act as undesired proxy
 
Always:
 - don't access user supplied urls (without proper validation, whitelisting, etc....)
 - if full validation is not possible at least 
   - limit allowed protocols
   - resolve IPs and limit internal ones 
   - have denylist 
   - don't include or validate url parameters, etc.....
   - don't follow redirects, bind to ip (to avoid DNS rebinding problems), .....
   - always enforce authentication for internal systems normally used by system


```
public static Uri RebindToIp(this Uri uri, IPAddress ipAddress)
{
    var portPart = uri.IsDefaultPort ? "": $":{uri.Port.ToString()}";
    var uriStr = $"{uri.Scheme}://{ipAddress.ToString()}{portPart}{uri.PathAndQuery}";
    return new Uri(uriStr);
}

public static string GetData(string url)
{
    // Check scheme 
    var uri = new Uri(url);
    if (uri.Scheme != "https")
    {
        throw new Exception("Only https scheme is allowed.");
    }
    
    // Check host against allowlist
    string[] allowedHosts = {"www.securecodewarrior.com", "scw.io"};
    bool hostAllowed = false;
    foreach (string allowedHost in allowedHosts)
    {
        if (uri.Host.Equals(allowedHost, StringComparison.OrdinalIgnoreCase))
        {
            hostAllowed = true;
            break;
        }
    }
    if (!hostAllowed)
    {
        throw new Exception("The host is not in the allowed list.");
    }
    
    // Resolve the IP address and deny local ones
    IPAddress[] addresses = Dns.GetHostAddresses(uri.Host);
    IPAddress address = addresses[0];
    if (IPAddress.IsLoopback(address) || IPAddress.IsLinkLocal(address) || IPAddress.IsSiteLocal(address) || IPAddress.IsPrivate(address))
    {
        throw new Exception("The resolved IP address is a private, loopback, link local or site local address.");
    }
    
    // Connect to the host by IP and block redirects
    var clientHandler = new HttpClientHandler
    {
        AllowAutoRedirect = false
    };
    var client = new HttpClient(clientHandler);
    client.DefaultRequestHeaders.Host = uri.Host;
    HttpResponseMessage response = client.GetAsync(uri.RebindToIp(address)).Result;
    return response.Content.ReadAsStringAsync().Result;
}

```

More info:
 - [CWE-918: Server-Side Request Forgery (SSRF)](https://cwe.mitre.org/data/definitions/918.html)
 - [OWASP Top 10:2021 A10 – Server-Side Request Forgery (SSRF)](https://owasp.org/Top10/A10_2021-Server-Side_Request_Forgery_%28SSRF%29/)
 - [SSRF Cheat Sheet](https://cheatsheetseries.owasp.org/cheatsheets/Server_Side_Request_Forgery_Prevention_Cheat_Sheet.html)
 - [SSRF Bible](https://cheatsheetseries.owasp.org/assets/Server_Side_Request_Forgery_Prevention_Cheat_Sheet_SSRF_Bible.pdf)

## Resources

1.  [Secure Coding Warrior](https://portal.securecodewarrior.com/)

https://mi-2a7bcb45-872c-4adf-ba34-96af1fc52fef-0.mission.securecodewarrior.com/statements/download/999?fallbackUrl=https://mi-2a7bcb45-872c-4adf-ba34-96af1fc52fef-0.mission.securecodewarrior.com/api/transactions/getlatest/94923054
https://mi-2a7bcb45-872c-4adf-ba34-96af1fc52fef-0.mission.securecodewarrior.com/statements/download/999?fallbackUrl=https%3A%2F%2Fmi-2a7bcb45-872c-4adf-ba34-96af1fc52fef-0.mission.securecodewarrior.com%2Fapi%2Ftransactions%2Fgetlatest%2F94923054
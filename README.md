The directory is structured with performance_modelling, configuration, and execution as separate modules.

Client, Instance and Function level API's are defined in the configuration, along with methods to configure the minimum instance groups for client manifest. Execution contains the gateway throguh which clients make requests, and the scheduler that schedules instances to run based on the configured environment and candidate list. The performance_modelling dir contaisn the offline performance models for function typesover varying input domains and resource configs as described in the paper. The performance models configured offline are used at runtime configure the environment based on client manifest. 

Execution based environment and API is defined in execution/, where scheduler provides the scheduling service and the gateway provides an API for a point of entry into the FaaS system for the client, as described in the paper.

Still under development.